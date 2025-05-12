"""
This script generates a list of colors for Sola::Graphics::Color from rgb.txt (big thanks to XKCD)
"""

from colorsys import rgb_to_hls
from pathlib import Path


OUTPUT_FILENAME = "rgb.hpp"


current_dir = Path(".") / "scripts"
with open(current_dir / "rgb.txt", "r", encoding="utf-8") as inp:
    lines = inp.readlines()

# Removing comments, they start with # symbol
lines = [line.strip() for line in lines if line.strip()[0] != "#"]


# Separating color names and values
def make_color_from_str(color_code: str) -> tuple[int, int, int]:
    color_code = color_code.removeprefix("#")
    red = int(color_code[:2], 16)
    green = int(color_code[2:4], 16)
    blue = int(color_code[4:], 16)
    return (red, green, blue)


colors = {make_color_from_str(line.split("\t")[1]): line.split("\t") for line in lines}


# Sorting colors from brightest to darkest
def color_key(color: tuple[int, int, int]) -> int:
    red, green, blue = map(lambda x: x / 255, color)
    hue, lightness, saturation = rgb_to_hls(red, green, blue)
    lightness = 1 - lightness
    saturation = 1 - saturation
    return (int(lightness * 255) << 16) + (int(saturation * 255) << 8) + int(hue * 255)


sorted_colors = sorted(colors.keys(), key=color_key)


def make_cpp_name(original_name: str) -> str:
    result = original_name.replace("-", "_").replace("'", "").replace(" ", "_").replace("/", "_")
    while "__" in result:
        result = result.replace("__", "_")
    return result


# Needed for handling cases when colors share same name
printed_colors: dict[str, tuple[int, int, int]] = {}


def handle_same_color_name(color_name: str, rgb: tuple[int, int, int]) -> str | None:
    prev_r, prev_g, prev_b = map(lambda x: x / 255, printed_colors[color_name])
    curr_r, curr_g, curr_b = map(lambda x: x / 255, rgb)
    _, prev_l, _ = rgb_to_hls(prev_r, prev_g, prev_b)
    _, curr_l, _ = rgb_to_hls(curr_r, curr_g, curr_b)
    if abs(curr_l - prev_l) < 0.0001:
        return None
    elif curr_l > prev_l:
        color_name += " Lighter"
    elif curr_l < prev_l:
        color_name += " Darker"
    result: str | None = color_name
    if color_name in printed_colors:
        result = handle_same_color_name(color_name, rgb)
    return result


with open(current_dir / OUTPUT_FILENAME, "w", encoding="utf-8") as out:
    for rgb in sorted_colors:
        color = colors[rgb]
        color_name = make_cpp_name(color[0]).replace("_", " ").title()
        if color_name in printed_colors:
            color_name = handle_same_color_name(color_name, rgb)
            if color_name is None:
                continue
        printed_colors[color_name] = rgb
        color_hex = color[1].removeprefix("#")
        r, g, b = rgb
        # We need documentation. But even if it's dumb?..
        print(f"/// @brief {color_name} rgb({r}, {g}, {b})", file=out)
        print(f"inline constexpr u32 {make_cpp_name(color_name)} = 0x{color_hex};", file=out)
