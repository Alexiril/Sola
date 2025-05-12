#ifndef SOLA_GRAPHICS_COLOR
#define SOLA_GRAPHICS_COLOR

#include "sola_common.hpp"

namespace Sola
{
    namespace Graphics
    {
        /// @brief This namespace contains colors used for debugging or profiling purposes.
        namespace DebugColor
        {
            /// @brief Used for generic purposes, shows the most important stuff
            inline constexpr u32 MainDebugColor = Color::Amber;
            /// @brief Used for generic purposes, shows important stuff
            inline constexpr u32 SecondaryDebugColor = Color::Purple_HTML;
            /// @brief Used for generic purposes, shows other stuff
            inline constexpr u32 TernaryDebugColor = Color::Teal;

            /// @brief This color should be used only if there is an important issue found
            inline constexpr u32 DangerousDebugColor = Color::Red_Crayola;
        } // namespace DebugColor

        /// @brief This namespace contains most of named color variables and some other color related stuff.
        ///
        /// Color list written in this namespace was copied from the list of colors in
        /// [Wikipedia](https://en.wikipedia.org/wiki/List_of_colors_(alphabetical)). There is no automatic
        /// synchronization with the Wikipedia list, so it should be synchronized manually (or via script) if needed.
        /// All complaints about color names should be directed to Wikipedia, yes, Purple_HTML instead of just Purple.
        ///
        /// @todo Maybe fix this naming mess and rename the colors to be consistent?..
        namespace Color
        {
            /// @brief White rgb(255, 255, 255)
            inline constexpr u32 White = 0xffffff;
            /// @brief Tooth rgb(255, 250, 250)
            inline constexpr u32 Tooth = 0xfffafa;
            /// @brief Lotion rgb(254, 253, 250)
            inline constexpr u32 Lotion = 0xfefdfa;
            /// @brief Baby powder rgb(254, 254, 250)
            inline constexpr u32 Baby_powder = 0xfefefa;
            /// @brief Ghost white rgb(248, 248, 255)
            inline constexpr u32 Ghost_white = 0xf8f8ff;
            /// @brief Milk rgb(253, 255, 245)
            inline constexpr u32 Milk = 0xfdfff5;
            /// @brief Mint cream rgb(245, 255, 250)
            inline constexpr u32 Mint_cream = 0xf5fffa;
            /// @brief Floral white rgb(255, 250, 240)
            inline constexpr u32 Floral_white = 0xfffaf0;
            /// @brief Ivory rgb(255, 255, 240)
            inline constexpr u32 Ivory = 0xfffff0;
            /// @brief Honeydew rgb(240, 255, 240)
            inline constexpr u32 Honeydew = 0xf0fff0;
            /// @brief Azure (X11/web color) rgb(240, 255, 255)
            inline constexpr u32 Azure_X11_web_color = 0xf0ffff;
            /// @brief Alice blue rgb(240, 248, 255)
            inline constexpr u32 Alice_blue = 0xf0f8ff;
            /// @brief Seashell rgb(255, 245, 238)
            inline constexpr u32 Seashell = 0xfff5ee;
            /// @brief Cultured rgb(245, 245, 245)
            inline constexpr u32 Cultured = 0xf5f5f5;
            /// @brief White smoke rgb(245, 245, 245)
            inline constexpr u32 White_smoke = 0xf5f5f5;
            /// @brief Zebra White rgb(245, 245, 245)
            inline constexpr u32 Zebra_White = 0xf5f5f5;
            /// @brief Cosmic latte rgb(255, 248, 231)
            inline constexpr u32 Cosmic_latte = 0xfff8e7;
            /// @brief Old lace rgb(253, 245, 230)
            inline constexpr u32 Old_lace = 0xfdf5e6;
            /// @brief Misty rose rgb(255, 228, 225)
            inline constexpr u32 Misty_rose = 0xffe4e1;
            /// @brief Light cyan rgb(224, 255, 255)
            inline constexpr u32 Light_cyan = 0xe0ffff;
            /// @brief Linen rgb(250, 240, 230)
            inline constexpr u32 Linen = 0xfaf0e6;
            /// @brief Lavender (web) rgb(230, 230, 250)
            inline constexpr u32 Lavender_web = 0xe6e6fa;
            /// @brief Lavender mist rgb(230, 230, 250)
            inline constexpr u32 Lavender_mist = 0xe6e6fa;
            /// @brief Isabelline rgb(244, 240, 236)
            inline constexpr u32 Isabelline = 0xf4f0ec;
            /// @brief Pink lace rgb(255, 221, 244)
            inline constexpr u32 Pink_lace = 0xffddf4;
            /// @brief Cornsilk rgb(255, 248, 220)
            inline constexpr u32 Cornsilk = 0xfff8dc;
            /// @brief Nyanza rgb(233, 255, 219)
            inline constexpr u32 Nyanza = 0xe9ffdb;
            /// @brief Piggy pink rgb(253, 221, 230)
            inline constexpr u32 Piggy_pink = 0xfddde6;
            /// @brief Mimi pink rgb(255, 218, 233)
            inline constexpr u32 Mimi_pink = 0xffdae9;
            /// @brief Alabaster rgb(242, 240, 230)
            inline constexpr u32 Alabaster = 0xf2f0e6;
            /// @brief Petal rgb(245, 226, 226)
            inline constexpr u32 Petal = 0xf5e2e2;
            /// @brief Papaya whip rgb(255, 239, 213)
            inline constexpr u32 Papaya_whip = 0xffefd5;
            /// @brief Pale pink rgb(250, 218, 221)
            inline constexpr u32 Pale_pink = 0xfadadd;
            /// @brief Antique white rgb(250, 235, 215)
            inline constexpr u32 Antique_white = 0xfaebd7;
            /// @brief Moccasin rgb(250, 235, 215)
            inline constexpr u32 Moccasin = 0xfaebd7;
            /// @brief Beige rgb(245, 245, 220)
            inline constexpr u32 Beige = 0xf5f5dc;
            /// @brief Cream rgb(255, 253, 208)
            inline constexpr u32 Cream = 0xfffdd0;
            /// @brief Pale lavender rgb(220, 208, 255)
            inline constexpr u32 Pale_lavender = 0xdcd0ff;
            /// @brief Lumber rgb(255, 228, 205)
            inline constexpr u32 Lumber = 0xffe4cd;
            /// @brief Blanched almond rgb(255, 235, 205)
            inline constexpr u32 Blanched_almond = 0xffebcd;
            /// @brief Lemon chiffon rgb(255, 250, 205)
            inline constexpr u32 Lemon_chiffon = 0xfffacd;
            /// @brief Shampoo rgb(255, 207, 241)
            inline constexpr u32 Shampoo = 0xffcff1;
            /// @brief Water rgb(212, 241, 249)
            inline constexpr u32 Water = 0xd4f1f9;
            /// @brief Pink Diamond (Ace Hardware Color) rgb(246, 214, 222)
            inline constexpr u32 Pink_Diamond_Ace_Hardware_Color = 0xf6d6de;
            /// @brief Lavender blue rgb(204, 204, 255)
            inline constexpr u32 Lavender_blue = 0xccccff;
            /// @brief Periwinkle rgb(204, 204, 255)
            inline constexpr u32 Periwinkle = 0xccccff;
            /// @brief Light red rgb(255, 204, 203)
            inline constexpr u32 Light_red = 0xffcccb;
            /// @brief Unbleached silk rgb(255, 221, 202)
            inline constexpr u32 Unbleached_silk = 0xffddca;
            /// @brief Platinum rgb(229, 228, 226)
            inline constexpr u32 Platinum = 0xe5e4e2;
            /// @brief Champagne rgb(247, 231, 206)
            inline constexpr u32 Champagne = 0xf7e7ce;
            /// @brief Eggshell rgb(240, 234, 214)
            inline constexpr u32 Eggshell = 0xf0ead6;
            /// @brief Bisque rgb(255, 228, 196)
            inline constexpr u32 Bisque = 0xffe4c4;
            /// @brief Parchment rgb(241, 233, 210)
            inline constexpr u32 Parchment = 0xf1e9d2;
            /// @brief Pink Diamond (Independent Retailers Colors) rgb(240, 211, 220)
            inline constexpr u32 Pink_Diamond_Independent_Retailers_Colors = 0xf0d3dc;
            /// @brief White chocolate rgb(237, 230, 214)
            inline constexpr u32 White_chocolate = 0xede6d6;
            /// @brief Pink rgb(255, 192, 203)
            inline constexpr u32 Pink = 0xffc0cb;
            /// @brief Champagne pink rgb(241, 221, 207)
            inline constexpr u32 Champagne_pink = 0xf1ddcf;
            /// @brief Very pale orange rgb(255, 223, 191)
            inline constexpr u32 Very_pale_orange = 0xffdfbf;
            /// @brief Very pale yellow rgb(255, 255, 191)
            inline constexpr u32 Very_pale_yellow = 0xffffbf;
            /// @brief Almond rgb(239, 222, 205)
            inline constexpr u32 Almond = 0xefdecd;
            /// @brief Cotton candy rgb(255, 188, 217)
            inline constexpr u32 Cotton_candy = 0xffbcd9;
            /// @brief Lotion pink rgb(236, 207, 207)
            inline constexpr u32 Lotion_pink = 0xeccfcf;
            /// @brief White coffee rgb(230, 224, 212)
            inline constexpr u32 White_coffee = 0xe6e0d4;
            /// @brief Peach puff rgb(255, 218, 185)
            inline constexpr u32 Peach_puff = 0xffdab9;
            /// @brief Gainsboro rgb(220, 220, 220)
            inline constexpr u32 Gainsboro = 0xdcdcdc;
            /// @brief Cherry blossom pink rgb(255, 183, 197)
            inline constexpr u32 Cherry_blossom_pink = 0xffb7c5;
            /// @brief Baby pink rgb(244, 194, 194)
            inline constexpr u32 Baby_pink = 0xf4c2c2;
            /// @brief Tea rose rgb(244, 194, 194)
            inline constexpr u32 Tea_rose = 0xf4c2c2;
            /// @brief Soap rgb(206, 200, 239)
            inline constexpr u32 Soap = 0xcec8ef;
            /// @brief Spanish pink rgb(247, 191, 190)
            inline constexpr u32 Spanish_pink = 0xf7bfbe;
            /// @brief Lemon meringue rgb(246, 234, 190)
            inline constexpr u32 Lemon_meringue = 0xf6eabe;
            /// @brief Queen pink rgb(232, 204, 215)
            inline constexpr u32 Queen_pink = 0xe8ccd7;
            /// @brief Peach rgb(255, 229, 180)
            inline constexpr u32 Peach = 0xffe5b4;
            /// @brief Celeste rgb(178, 255, 255)
            inline constexpr u32 Celeste = 0xb2ffff;
            /// @brief Italian sky blue rgb(178, 255, 255)
            inline constexpr u32 Italian_sky_blue = 0xb2ffff;
            /// @brief Melon rgb(253, 188, 180)
            inline constexpr u32 Melon = 0xfdbcb4;
            /// @brief Little girl pink rgb(248, 185, 212)
            inline constexpr u32 Little_girl_pink = 0xf8b9d4;
            /// @brief Pearl rgb(234, 224, 200)
            inline constexpr u32 Pearl = 0xeae0c8;
            /// @brief Mauve rgb(224, 176, 255)
            inline constexpr u32 Mauve = 0xe0b0ff;
            /// @brief Banana Mania rgb(250, 231, 181)
            inline constexpr u32 Banana_Mania = 0xfae7b5;
            /// @brief Orchid pink rgb(242, 189, 205)
            inline constexpr u32 Orchid_pink = 0xf2bdcd;
            /// @brief Tea green rgb(208, 240, 192)
            inline constexpr u32 Tea_green = 0xd0f0c0;
            /// @brief Light silver rgb(216, 216, 216)
            inline constexpr u32 Light_silver = 0xd8d8d8;
            /// @brief Navajo white rgb(255, 222, 173)
            inline constexpr u32 Navajo_white = 0xffdead;
            /// @brief Timberwolf rgb(219, 215, 210)
            inline constexpr u32 Timberwolf = 0xdbd7d2;
            /// @brief Melon (Crayola) rgb(254, 186, 173)
            inline constexpr u32 Melon_Crayola = 0xfebaad;
            /// @brief Apricot rgb(251, 206, 177)
            inline constexpr u32 Apricot = 0xfbceb1;
            /// @brief Bone rgb(227, 218, 201)
            inline constexpr u32 Bone = 0xe3dac9;
            /// @brief Dutch white rgb(239, 223, 187)
            inline constexpr u32 Dutch_white = 0xefdfbb;
            /// @brief Cameo pink rgb(239, 187, 204)
            inline constexpr u32 Cameo_pink = 0xefbbcc;
            /// @brief Pale spring bud rgb(236, 235, 189)
            inline constexpr u32 Pale_spring_bud = 0xecebbd;
            /// @brief Spring green (Crayola) rgb(236, 235, 189)
            inline constexpr u32 Spring_green_Crayola = 0xecebbd;
            /// @brief Periwinkle (Crayola) rgb(195, 205, 230)
            inline constexpr u32 Periwinkle_Crayola = 0xc3cde6;
            /// @brief Wheat rgb(245, 222, 179)
            inline constexpr u32 Wheat = 0xf5deb3;
            /// @brief Languid lavender rgb(214, 202, 221)
            inline constexpr u32 Languid_lavender = 0xd6cadd;
            /// @brief Carnation pink rgb(255, 166, 201)
            inline constexpr u32 Carnation_pink = 0xffa6c9;
            /// @brief Rich brilliant lavender rgb(241, 167, 254)
            inline constexpr u32 Rich_brilliant_lavender = 0xf1a7fe;
            /// @brief Columbia Blue rgb(196, 216, 226)
            inline constexpr u32 Columbia_Blue = 0xc4d8e2;
            /// @brief Light periwinkle rgb(197, 203, 225)
            inline constexpr u32 Light_periwinkle = 0xc5cbe1;
            /// @brief Peach (Crayola) rgb(255, 203, 164)
            inline constexpr u32 Peach_Crayola = 0xffcba4;
            /// @brief Nadeshiko pink rgb(246, 173, 198)
            inline constexpr u32 Nadeshiko_pink = 0xf6adc6;
            /// @brief Beau blue rgb(188, 212, 230)
            inline constexpr u32 Beau_blue = 0xbcd4e6;
            /// @brief Pale aqua rgb(188, 212, 230)
            inline constexpr u32 Pale_aqua = 0xbcd4e6;
            /// @brief Deep champagne rgb(250, 214, 165)
            inline constexpr u32 Deep_champagne = 0xfad6a5;
            /// @brief Sunset rgb(250, 214, 165)
            inline constexpr u32 Sunset = 0xfad6a5;
            /// @brief Lemon yellow (Crayola) rgb(255, 255, 159)
            inline constexpr u32 Lemon_yellow_Crayola = 0xffff9f;
            /// @brief Waterspout rgb(164, 244, 249)
            inline constexpr u32 Waterspout = 0xa4f4f9;
            /// @brief Medium champagne rgb(243, 229, 171)
            inline constexpr u32 Medium_champagne = 0xf3e5ab;
            /// @brief Vanilla rgb(243, 229, 171)
            inline constexpr u32 Vanilla = 0xf3e5ab;
            /// @brief Pale blue rgb(175, 238, 238)
            inline constexpr u32 Pale_blue = 0xafeeee;
            /// @brief Pale turquoise rgb(175, 238, 238)
            inline constexpr u32 Pale_turquoise = 0xafeeee;
            /// @brief Desert sand rgb(237, 201, 175)
            inline constexpr u32 Desert_sand = 0xedc9af;
            /// @brief Lavender rose rgb(251, 160, 227)
            inline constexpr u32 Lavender_rose = 0xfba0e3;
            /// @brief Menthol rgb(193, 249, 162)
            inline constexpr u32 Menthol = 0xc1f9a2;
            /// @brief Maximum pink rgb(246, 165, 242)
            inline constexpr u32 Maximum_pink = 0xf6a5f2;
            /// @brief Magic Mint rgb(170, 240, 209)
            inline constexpr u32 Magic_Mint = 0xaaf0d1;
            /// @brief Neon Carrot rgb(170, 240, 209)
            inline constexpr u32 Neon_Carrot = 0xaaf0d1;
            /// @brief Pale cornflower blue rgb(171, 205, 239)
            inline constexpr u32 Pale_cornflower_blue = 0xabcdef;
            /// @brief Thistle (Crayola) rgb(235, 176, 215)
            inline constexpr u32 Thistle_Crayola = 0xebb0d7;
            /// @brief Light salmon pink rgb(255, 153, 153)
            inline constexpr u32 Light_salmon_pink = 0xff9999;
            /// @brief Canary rgb(255, 255, 153)
            inline constexpr u32 Canary = 0xffff99;
            /// @brief Pale violet rgb(204, 153, 255)
            inline constexpr u32 Pale_violet = 0xcc99ff;
            /// @brief Pale goldenrod rgb(238, 232, 170)
            inline constexpr u32 Pale_goldenrod = 0xeee8aa;
            /// @brief Neon silver rgb(204, 204, 204)
            inline constexpr u32 Neon_silver = 0xcccccc;
            /// @brief Mint green rgb(152, 255, 152)
            inline constexpr u32 Mint_green = 0x98ff98;
            /// @brief Powder blue rgb(176, 224, 230)
            inline constexpr u32 Powder_blue = 0xb0e0e6;
            /// @brief Thistle rgb(216, 191, 216)
            inline constexpr u32 Thistle = 0xd8bfd8;
            /// @brief Blue-gray (Crayola) rgb(200, 200, 205)
            inline constexpr u32 Blue_gray_Crayola = 0xc8c8cd;
            /// @brief Pastel yellow rgb(253, 253, 150)
            inline constexpr u32 Pastel_yellow = 0xfdfd96;
            /// @brief Pale green rgb(152, 251, 152)
            inline constexpr u32 Pale_green = 0x98fb98;
            /// @brief Metallic pink rgb(237, 166, 196)
            inline constexpr u32 Metallic_pink = 0xeda6c4;
            /// @brief Pink pearl rgb(231, 172, 207)
            inline constexpr u32 Pink_pearl = 0xe7accf;
            /// @brief Maximum Blue Purple rgb(172, 172, 230)
            inline constexpr u32 Maximum_Blue_Purple = 0xacace6;
            /// @brief Lavender gray rgb(196, 195, 208)
            inline constexpr u32 Lavender_gray = 0xc4c3d0;
            /// @brief Pastel gray rgb(207, 207, 196)
            inline constexpr u32 Pastel_gray = 0xcfcfc4;
            /// @brief Baby blue eyes rgb(161, 202, 241)
            inline constexpr u32 Baby_blue_eyes = 0xa1caf1;
            /// @brief Non-photo blue rgb(164, 221, 237)
            inline constexpr u32 Non_photo_blue = 0xa4dded;
            /// @brief Baker-Miller pink rgb(255, 145, 175)
            inline constexpr u32 Baker_Miller_pink = 0xff91af;
            /// @brief Schauss pink rgb(255, 145, 175)
            inline constexpr u32 Schauss_pink = 0xff91af;
            /// @brief Salmon pink rgb(255, 145, 164)
            inline constexpr u32 Salmon_pink = 0xff91a4;
            /// @brief Pastel magenta rgb(244, 154, 194)
            inline constexpr u32 Pastel_magenta = 0xf49ac2;
            /// @brief Amaranth pink rgb(241, 156, 187)
            inline constexpr u32 Amaranth_pink = 0xf19cbb;
            /// @brief Light orchid rgb(230, 168, 215)
            inline constexpr u32 Light_orchid = 0xe6a8d7;
            /// @brief Celadon rgb(172, 225, 175)
            inline constexpr u32 Celadon = 0xace1af;
            /// @brief Light Moss Green rgb(173, 223, 173)
            inline constexpr u32 Light_Moss_Green = 0xaddfad;
            /// @brief Pale chestnut rgb(221, 173, 175)
            inline constexpr u32 Pale_chestnut = 0xddadaf;
            /// @brief Macaroni and Cheese rgb(255, 189, 136)
            inline constexpr u32 Macaroni_and_Cheese = 0xffbd88;
            /// @brief Mauvelous rgb(239, 152, 170)
            inline constexpr u32 Mauvelous = 0xef98aa;
            /// @brief Tulip rgb(255, 135, 141)
            inline constexpr u32 Tulip = 0xff878d;
            /// @brief Tickle Me Pink rgb(252, 137, 172)
            inline constexpr u32 Tickle_Me_Pink = 0xfc89ac;
            /// @brief Pink Sherbet rgb(247, 143, 167)
            inline constexpr u32 Pink_Sherbet = 0xf78fa7;
            /// @brief Kobi rgb(231, 159, 196)
            inline constexpr u32 Kobi = 0xe79fc4;
            /// @brief Granny Smith apple rgb(168, 228, 160)
            inline constexpr u32 Granny_Smith_apple = 0xa8e4a0;
            /// @brief Pale silver rgb(201, 192, 187)
            inline constexpr u32 Pale_silver = 0xc9c0bb;
            /// @brief Silver (Crayola) rgb(201, 192, 187)
            inline constexpr u32 Silver_Crayola = 0xc9c0bb;
            /// @brief Mindaro rgb(227, 249, 136)
            inline constexpr u32 Mindaro = 0xe3f988;
            /// @brief Vanilla ice rgb(243, 143, 169)
            inline constexpr u32 Vanilla_ice = 0xf38fa9;
            /// @brief Green-yellow (Crayola) rgb(240, 232, 145)
            inline constexpr u32 Green_yellow_Crayola = 0xf0e891;
            /// @brief Pastel pink rgb(222, 165, 164)
            inline constexpr u32 Pastel_pink = 0xdea5a4;
            /// @brief Silver sand rgb(191, 193, 194)
            inline constexpr u32 Silver_sand = 0xbfc1c2;
            /// @brief Yellow (Crayola) rgb(252, 232, 131)
            inline constexpr u32 Yellow_Crayola = 0xfce883;
            /// @brief Pale cyan rgb(135, 211, 248)
            inline constexpr u32 Pale_cyan = 0x87d3f8;
            /// @brief Key lime rgb(232, 244, 140)
            inline constexpr u32 Key_lime = 0xe8f48c;
            /// @brief Bright lilac rgb(216, 145, 239)
            inline constexpr u32 Bright_lilac = 0xd891ef;
            /// @brief Teal deer rgb(153, 230, 179)
            inline constexpr u32 Teal_deer = 0x99e6b3;
            /// @brief Silver rgb(192, 192, 192)
            inline constexpr u32 Silver = 0xc0c0c0;
            /// @brief Aquamarine rgb(127, 255, 212)
            inline constexpr u32 Aquamarine = 0x7fffd4;
            /// @brief Light fuchsia pink rgb(249, 132, 239)
            inline constexpr u32 Light_fuchsia_pink = 0xf984ef;
            /// @brief Pale magenta rgb(249, 132, 229)
            inline constexpr u32 Pale_magenta = 0xf984e5;
            /// @brief Cornflower blue (Crayola) rgb(147, 204, 234)
            inline constexpr u32 Cornflower_blue_Crayola = 0x93ccea;
            /// @brief Light cornflower blue rgb(147, 204, 234)
            inline constexpr u32 Light_cornflower_blue = 0x93ccea;
            /// @brief Aquamarine (Crayola) rgb(149, 224, 232)
            inline constexpr u32 Aquamarine_Crayola = 0x95e0e8;
            /// @brief Pale cerulean rgb(155, 196, 226)
            inline constexpr u32 Pale_cerulean = 0x9bc4e2;
            /// @brief Orchid (Crayola) rgb(226, 156, 210)
            inline constexpr u32 Orchid_Crayola = 0xe29cd2;
            /// @brief Medium lavender magenta rgb(221, 160, 221)
            inline constexpr u32 Medium_lavender_magenta = 0xdda0dd;
            /// @brief Pale plum rgb(221, 160, 221)
            inline constexpr u32 Pale_plum = 0xdda0dd;
            /// @brief Plum (web) rgb(221, 160, 221)
            inline constexpr u32 Plum_web = 0xdda0dd;
            /// @brief Pastel blue rgb(174, 198, 207)
            inline constexpr u32 Pastel_blue = 0xaec6cf;
            /// @brief Topaz rgb(255, 200, 124)
            inline constexpr u32 Topaz = 0xffc87c;
            /// @brief Electric blue rgb(125, 249, 255)
            inline constexpr u32 Electric_blue = 0x7df9ff;
            /// @brief Khaki (X11) (Light khaki) rgb(240, 230, 140)
            inline constexpr u32 Khaki_X11_Light_khaki = 0xf0e68c;
            /// @brief Wisteria rgb(201, 160, 220)
            inline constexpr u32 Wisteria = 0xc9a0dc;
            /// @brief Gray (X11) rgb(190, 190, 190)
            inline constexpr u32 Gray_X11 = 0xbebebe;
            /// @brief Baby blue rgb(137, 207, 240)
            inline constexpr u32 Baby_blue = 0x89cff0;
            /// @brief Dark vanilla rgb(209, 190, 168)
            inline constexpr u32 Dark_vanilla = 0xd1bea8;
            /// @brief Very light tangelo rgb(255, 176, 119)
            inline constexpr u32 Very_light_tangelo = 0xffb077;
            /// @brief Jasmine rgb(248, 222, 126)
            inline constexpr u32 Jasmine = 0xf8de7e;
            /// @brief Mellow yellow rgb(248, 222, 126)
            inline constexpr u32 Mellow_yellow = 0xf8de7e;
            /// @brief Persian pink rgb(247, 127, 190)
            inline constexpr u32 Persian_pink = 0xf77fbe;
            /// @brief Turquoise green rgb(160, 214, 180)
            inline constexpr u32 Turquoise_green = 0xa0d6b4;
            /// @brief French sky blue rgb(119, 181, 254)
            inline constexpr u32 French_sky_blue = 0x77b5fe;
            /// @brief Charm pink rgb(230, 143, 172)
            inline constexpr u32 Charm_pink = 0xe68fac;
            /// @brief Light Thulian pink rgb(230, 143, 172)
            inline constexpr u32 Light_Thulian_pink = 0xe68fac;
            /// @brief Pale robin egg blue rgb(150, 222, 209)
            inline constexpr u32 Pale_robin_egg_blue = 0x96ded1;
            /// @brief Light pastel purple rgb(177, 156, 217)
            inline constexpr u32 Light_pastel_purple = 0xb19cd9;
            /// @brief Heliotrope rgb(223, 115, 255)
            inline constexpr u32 Heliotrope = 0xdf73ff;
            /// @brief Pink flamingo rgb(252, 116, 253)
            inline constexpr u32 Pink_flamingo = 0xfc74fd;
            /// @brief Congo pink rgb(248, 131, 121)
            inline constexpr u32 Congo_pink = 0xf88379;
            /// @brief Coral pink rgb(248, 131, 121)
            inline constexpr u32 Coral_pink = 0xf88379;
            /// @brief Tea rose rgb(248, 131, 121)
            inline constexpr u32 Tea_rose = 0xf88379;
            /// @brief Buff rgb(240, 220, 130)
            inline constexpr u32 Buff = 0xf0dc82;
            /// @brief Sky blue rgb(135, 206, 235)
            inline constexpr u32 Sky_blue = 0x87ceeb;
            /// @brief Salmon Rose rgb(231, 150, 139)
            inline constexpr u32 Salmon_Rose = 0xe7968b;
            /// @brief Blue bell rgb(162, 162, 208)
            inline constexpr u32 Blue_bell = 0xa2a2d0;
            /// @brief Silver pink rgb(196, 174, 173)
            inline constexpr u32 Silver_pink = 0xc4aead;
            /// @brief Shandy rgb(255, 230, 112)
            inline constexpr u32 Shandy = 0xffe670;
            /// @brief Very light azure rgb(116, 187, 251)
            inline constexpr u32 Very_light_azure = 0x74bbfb;
            /// @brief Mellow apricot rgb(248, 184, 120)
            inline constexpr u32 Mellow_apricot = 0xf8b878;
            /// @brief Flax rgb(238, 220, 130)
            inline constexpr u32 Flax = 0xeedc82;
            /// @brief Lavender magenta rgb(238, 130, 238)
            inline constexpr u32 Lavender_magenta = 0xee82ee;
            /// @brief Violet (web) rgb(238, 130, 238)
            inline constexpr u32 Violet_web = 0xee82ee;
            /// @brief Gold (Crayola) rgb(230, 190, 138)
            inline constexpr u32 Gold_Crayola = 0xe6be8a;
            /// @brief Pale gold rgb(230, 190, 138)
            inline constexpr u32 Pale_gold = 0xe6be8a;
            /// @brief Ash gray rgb(178, 190, 181)
            inline constexpr u32 Ash_gray = 0xb2beb5;
            /// @brief Shocking pink (Crayola) rgb(255, 111, 255)
            inline constexpr u32 Shocking_pink_Crayola = 0xff6fff;
            /// @brief Ultra pink rgb(255, 111, 255)
            inline constexpr u32 Ultra_pink = 0xff6fff;
            /// @brief Maya blue rgb(115, 194, 251)
            inline constexpr u32 Maya_blue = 0x73c2fb;
            /// @brief Light medium orchid rgb(211, 155, 203)
            inline constexpr u32 Light_medium_orchid = 0xd39bcb;
            /// @brief Black Shadows rgb(191, 175, 178)
            inline constexpr u32 Black_Shadows = 0xbfafb2;
            /// @brief Medium pink rgb(254, 110, 159)
            inline constexpr u32 Medium_pink = 0xfe6e9f;
            /// @brief Salmon rgb(250, 128, 114)
            inline constexpr u32 Salmon = 0xfa8072;
            /// @brief Medium sky blue rgb(128, 218, 235)
            inline constexpr u32 Medium_sky_blue = 0x80daeb;
            /// @brief Opal rgb(168, 195, 188)
            inline constexpr u32 Opal = 0xa8c3bc;
            /// @brief French pink rgb(253, 108, 158)
            inline constexpr u32 French_pink = 0xfd6c9e;
            /// @brief Ultra red rgb(252, 108, 133)
            inline constexpr u32 Ultra_red = 0xfc6c85;
            /// @brief Wild watermelon rgb(252, 108, 133)
            inline constexpr u32 Wild_watermelon = 0xfc6c85;
            /// @brief Lilac rgb(200, 162, 200)
            inline constexpr u32 Lilac = 0xc8a2c8;
            /// @brief Hot pink rgb(255, 105, 180)
            inline constexpr u32 Hot_pink = 0xff69b4;
            /// @brief Yellow-green (Crayola) rgb(197, 227, 132)
            inline constexpr u32 Yellow_green_Crayola = 0xc5e384;
            /// @brief Light cobalt blue rgb(136, 172, 224)
            inline constexpr u32 Light_cobalt_blue = 0x88ace0;
            /// @brief Atomic tangerine rgb(255, 153, 102)
            inline constexpr u32 Atomic_tangerine = 0xff9966;
            /// @brief Laser Lemon rgb(255, 255, 102)
            inline constexpr u32 Laser_Lemon = 0xffff66;
            /// @brief Unmellow yellow rgb(255, 255, 102)
            inline constexpr u32 Unmellow_yellow = 0xffff66;
            /// @brief Screamin' green rgb(102, 255, 102)
            inline constexpr u32 Screamin_green = 0x66ff66;
            /// @brief Very light blue rgb(102, 102, 255)
            inline constexpr u32 Very_light_blue = 0x6666ff;
            /// @brief Burlywood rgb(222, 184, 135)
            inline constexpr u32 Burlywood = 0xdeb887;
            /// @brief Tumbleweed rgb(222, 170, 136)
            inline constexpr u32 Tumbleweed = 0xdeaa88;
            /// @brief Middle blue green rgb(141, 217, 204)
            inline constexpr u32 Middle_blue_green = 0x8dd9cc;
            /// @brief Light grayish magenta rgb(204, 153, 204)
            inline constexpr u32 Light_grayish_magenta = 0xcc99cc;
            /// @brief Philippine silver rgb(179, 179, 179)
            inline constexpr u32 Philippine_silver = 0xb3b3b3;
            /// @brief Cyclamen rgb(245, 111, 161)
            inline constexpr u32 Cyclamen = 0xf56fa1;
            /// @brief Dark salmon rgb(233, 150, 122)
            inline constexpr u32 Dark_salmon = 0xe9967a;
            /// @brief Aero rgb(124, 185, 232)
            inline constexpr u32 Aero = 0x7cb9e8;
            /// @brief Middle blue rgb(126, 212, 230)
            inline constexpr u32 Middle_blue = 0x7ed4e6;
            /// @brief Medium spring bud rgb(201, 220, 135)
            inline constexpr u32 Medium_spring_bud = 0xc9dc87;
            /// @brief Pastel violet rgb(203, 153, 201)
            inline constexpr u32 Pastel_violet = 0xcb99c9;
            /// @brief Cambridge blue rgb(163, 193, 173)
            inline constexpr u32 Cambridge_blue = 0xa3c1ad;
            /// @brief Middle yellow red rgb(236, 177, 118)
            inline constexpr u32 Middle_yellow_red = 0xecb176;
            /// @brief Dark sky blue rgb(140, 190, 214)
            inline constexpr u32 Dark_sky_blue = 0x8cbed6;
            /// @brief Pastel red rgb(255, 105, 97)
            inline constexpr u32 Pastel_red = 0xff6961;
            /// @brief Orange-yellow (Crayola) rgb(248, 213, 104)
            inline constexpr u32 Orange_yellow_Crayola = 0xf8d568;
            /// @brief Sky blue (Crayola) rgb(118, 215, 234)
            inline constexpr u32 Sky_blue_Crayola = 0x76d7ea;
            /// @brief Shimmering Blush rgb(217, 134, 149)
            inline constexpr u32 Shimmering_Blush = 0xd98695;
            /// @brief Pearl Aqua rgb(136, 216, 192)
            inline constexpr u32 Pearl_Aqua = 0x88d8c0;
            /// @brief Silver foil rgb(175, 177, 174)
            inline constexpr u32 Silver_foil = 0xafb1ae;
            /// @brief Light crimson rgb(245, 105, 145)
            inline constexpr u32 Light_crimson = 0xf56991;
            /// @brief Tan rgb(210, 180, 140)
            inline constexpr u32 Tan = 0xd2b48c;
            /// @brief Eton blue rgb(150, 200, 162)
            inline constexpr u32 Eton_blue = 0x96c8a2;
            /// @brief Lemon lime rgb(92, 255, 103)
            inline constexpr u32 Lemon_lime = 0x5cff67;
            /// @brief Bittersweet rgb(254, 111, 94)
            inline constexpr u32 Bittersweet = 0xfe6f5e;
            /// @brief Icterine rgb(252, 247, 94)
            inline constexpr u32 Icterine = 0xfcf75e;
            /// @brief Rajah rgb(251, 171, 96)
            inline constexpr u32 Rajah = 0xfbab60;
            /// @brief Brink pink rgb(251, 96, 127)
            inline constexpr u32 Brink_pink = 0xfb607f;
            /// @brief Lavender (floral) rgb(181, 126, 220)
            inline constexpr u32 Lavender_floral = 0xb57edc;
            /// @brief Middle purple rgb(217, 130, 181)
            inline constexpr u32 Middle_purple = 0xd982b5;
            /// @brief Naples yellow rgb(250, 218, 94)
            inline constexpr u32 Naples_yellow = 0xfada5e;
            /// @brief Royal yellow rgb(250, 218, 94)
            inline constexpr u32 Royal_yellow = 0xfada5e;
            /// @brief Stil de grain yellow rgb(250, 218, 94)
            inline constexpr u32 Stil_de_grain_yellow = 0xfada5e;
            /// @brief Middle red rgb(229, 142, 115)
            inline constexpr u32 Middle_red = 0xe58e73;
            /// @brief Tiffany Blue rgb(129, 216, 208)
            inline constexpr u32 Tiffany_Blue = 0x81d8d0;
            /// @brief Tuscany rgb(192, 153, 153)
            inline constexpr u32 Tuscany = 0xc09999;
            /// @brief Silver chalice rgb(172, 172, 172)
            inline constexpr u32 Silver_chalice = 0xacacac;
            /// @brief Mustard rgb(255, 219, 88)
            inline constexpr u32 Mustard = 0xffdb58;
            /// @brief Strawberry rgb(252, 90, 141)
            inline constexpr u32 Strawberry = 0xfc5a8d;
            /// @brief Strawberry iced tea rgb(252, 90, 141)
            inline constexpr u32 Strawberry_iced_tea = 0xfc5a8d;
            /// @brief Maize rgb(251, 236, 93)
            inline constexpr u32 Maize = 0xfbec5d;
            /// @brief Medium slate blue rgb(123, 104, 238)
            inline constexpr u32 Medium_slate_blue = 0x7b68ee;
            /// @brief New York pink rgb(215, 131, 127)
            inline constexpr u32 New_York_pink = 0xd7837f;
            /// @brief Laurel green rgb(169, 186, 157)
            inline constexpr u32 Laurel_green = 0xa9ba9d;
            /// @brief Silver (Metallic) rgb(170, 169, 173)
            inline constexpr u32 Silver_Metallic = 0xaaa9ad;
            /// @brief Sandy brown rgb(244, 164, 96)
            inline constexpr u32 Sandy_brown = 0xf4a460;
            /// @brief Fawn rgb(229, 170, 112)
            inline constexpr u32 Fawn = 0xe5aa70;
            /// @brief Candy pink rgb(228, 113, 122)
            inline constexpr u32 Candy_pink = 0xe4717a;
            /// @brief Tango pink rgb(228, 113, 122)
            inline constexpr u32 Tango_pink = 0xe4717a;
            /// @brief Pastel green rgb(119, 221, 119)
            inline constexpr u32 Pastel_green = 0x77dd77;
            /// @brief Vista blue rgb(124, 158, 217)
            inline constexpr u32 Vista_blue = 0x7c9ed9;
            /// @brief Puce rgb(204, 136, 153)
            inline constexpr u32 Puce = 0xcc8899;
            /// @brief Metallic silver rgb(168, 169, 173)
            inline constexpr u32 Metallic_silver = 0xa8a9ad;
            /// @brief Fiery rose rgb(255, 84, 112)
            inline constexpr u32 Fiery_rose = 0xff5470;
            /// @brief Arylide yellow rgb(233, 214, 107)
            inline constexpr u32 Arylide_yellow = 0xe9d66b;
            /// @brief Hansa yellow rgb(233, 214, 107)
            inline constexpr u32 Hansa_yellow = 0xe9d66b;
            /// @brief Straw rgb(228, 217, 111)
            inline constexpr u32 Straw = 0xe4d96f;
            /// @brief Khaki (web) (Khaki) rgb(195, 176, 145)
            inline constexpr u32 Khaki_web_Khaki = 0xc3b091;
            /// @brief Pastel purple rgb(179, 158, 181)
            inline constexpr u32 Pastel_purple = 0xb39eb5;
            /// @brief Cornflower blue (web) rgb(100, 149, 237)
            inline constexpr u32 Cornflower_blue_web = 0x6495ed;
            /// @brief Mocha rgb(190, 164, 147)
            inline constexpr u32 Mocha = 0xbea493;
            /// @brief Dark gray (X11) rgb(169, 169, 169)
            inline constexpr u32 Dark_gray_X11 = 0xa9a9a9;
            /// @brief Coral rgb(255, 127, 80)
            inline constexpr u32 Coral = 0xff7f50;
            /// @brief Sunset orange rgb(253, 94, 83)
            inline constexpr u32 Sunset_orange = 0xfd5e53;
            /// @brief Lemon yellow rgb(255, 244, 79)
            inline constexpr u32 Lemon_yellow = 0xfff44f;
            /// @brief Very light malachite green rgb(100, 233, 134)
            inline constexpr u32 Very_light_malachite_green = 0x64e986;
            /// @brief Brilliant rose rgb(230, 103, 206)
            inline constexpr u32 Brilliant_rose = 0xe667ce;
            /// @brief Light carmine pink rgb(230, 103, 113)
            inline constexpr u32 Light_carmine_pink = 0xe66771;
            /// @brief China pink rgb(222, 111, 161)
            inline constexpr u32 China_pink = 0xde6fa1;
            /// @brief Liseran purple rgb(222, 111, 161)
            inline constexpr u32 Liseran_purple = 0xde6fa1;
            /// @brief Thulian pink rgb(222, 111, 161)
            inline constexpr u32 Thulian_pink = 0xde6fa1;
            /// @brief Purple pizzazz rgb(254, 78, 218)
            inline constexpr u32 Purple_pizzazz = 0xfe4eda;
            /// @brief Watermelon rgb(240, 92, 133)
            inline constexpr u32 Watermelon = 0xf05c85;
            /// @brief Booger Buster rgb(221, 226, 106)
            inline constexpr u32 Booger_Buster = 0xdde26a;
            /// @brief Medium purple rgb(147, 112, 219)
            inline constexpr u32 Medium_purple = 0x9370db;
            /// @brief Pale violet-red rgb(219, 112, 147)
            inline constexpr u32 Pale_violet_red = 0xdb7093;
            /// @brief Dark sea green rgb(143, 188, 143)
            inline constexpr u32 Dark_sea_green = 0x8fbc8f;
            /// @brief Quick silver rgb(166, 166, 166)
            inline constexpr u32 Quick_silver = 0xa6a6a6;
            /// @brief Inchworm rgb(178, 236, 93)
            inline constexpr u32 Inchworm = 0xb2ec5d;
            /// @brief Blue jeans rgb(93, 173, 236)
            inline constexpr u32 Blue_jeans = 0x5dadec;
            /// @brief Little boy blue rgb(108, 160, 220)
            inline constexpr u32 Little_boy_blue = 0x6ca0dc;
            /// @brief Orchid rgb(218, 112, 214)
            inline constexpr u32 Orchid = 0xda70d6;
            /// @brief Orange-red (Crayola) rgb(255, 83, 73)
            inline constexpr u32 Orange_red_Crayola = 0xff5349;
            /// @brief Deep mauve rgb(212, 115, 212)
            inline constexpr u32 Deep_mauve = 0xd473d4;
            /// @brief French mauve rgb(212, 115, 212)
            inline constexpr u32 French_mauve = 0xd473d4;
            /// @brief Light French beige rgb(200, 173, 127)
            inline constexpr u32 Light_French_beige = 0xc8ad7f;
            /// @brief Tomato rgb(255, 99, 71)
            inline constexpr u32 Tomato = 0xff6347;
            /// @brief Pastel orange rgb(255, 179, 71)
            inline constexpr u32 Pastel_orange = 0xffb347;
            /// @brief Blueberry rgb(79, 134, 247)
            inline constexpr u32 Blueberry = 0x4f86f7;
            /// @brief Minion yellow rgb(245, 224, 80)
            inline constexpr u32 Minion_yellow = 0xf5e050;
            /// @brief Tan (Crayola) rgb(217, 154, 108)
            inline constexpr u32 Tan_Crayola = 0xd99a6c;
            /// @brief Sage rgb(188, 184, 138)
            inline constexpr u32 Sage = 0xbcb88a;
            /// @brief Glossy grape rgb(171, 146, 179)
            inline constexpr u32 Glossy_grape = 0xab92b3;
            /// @brief Lilac Luster rgb(174, 152, 170)
            inline constexpr u32 Lilac_Luster = 0xae98aa;
            /// @brief Medium aquamarine rgb(102, 221, 170)
            inline constexpr u32 Medium_aquamarine = 0x66ddaa;
            /// @brief Wild orchid rgb(212, 112, 162)
            inline constexpr u32 Wild_orchid = 0xd470a2;
            /// @brief Iceberg rgb(113, 166, 210)
            inline constexpr u32 Iceberg = 0x71a6d2;
            /// @brief Mango Tango rgb(255, 130, 67)
            inline constexpr u32 Mango_Tango = 0xff8243;
            /// @brief Yellow Orange rgb(255, 174, 66)
            inline constexpr u32 Yellow_Orange = 0xffae42;
            /// @brief Wild Strawberry rgb(255, 67, 164)
            inline constexpr u32 Wild_Strawberry = 0xff43a4;
            /// @brief Tart Orange rgb(251, 77, 70)
            inline constexpr u32 Tart_Orange = 0xfb4d46;
            /// @brief Lavender indigo rgb(148, 87, 235)
            inline constexpr u32 Lavender_indigo = 0x9457eb;
            /// @brief Navy purple rgb(148, 87, 235)
            inline constexpr u32 Navy_purple = 0x9457eb;
            /// @brief Neon purple rgb(148, 87, 235)
            inline constexpr u32 Neon_purple = 0x9457eb;
            /// @brief Big Foot Feet rgb(232, 142, 90)
            inline constexpr u32 Big_Foot_Feet = 0xe88e5a;
            /// @brief Pale copper rgb(218, 138, 103)
            inline constexpr u32 Pale_copper = 0xda8a67;
            /// @brief Antique brass rgb(205, 149, 117)
            inline constexpr u32 Antique_brass = 0xcd9575;
            /// @brief Ecru rgb(194, 178, 128)
            inline constexpr u32 Ecru = 0xc2b280;
            /// @brief Sand rgb(194, 178, 128)
            inline constexpr u32 Sand = 0xc2b280;
            /// @brief African violet rgb(178, 132, 190)
            inline constexpr u32 African_violet = 0xb284be;
            /// @brief Pewter blue rgb(139, 168, 183)
            inline constexpr u32 Pewter_blue = 0x8ba8b7;
            /// @brief Cadet grey rgb(145, 163, 176)
            inline constexpr u32 Cadet_grey = 0x91a3b0;
            /// @brief Manatee rgb(151, 154, 170)
            inline constexpr u32 Manatee = 0x979aaa;
            /// @brief Heliotrope gray rgb(170, 152, 169)
            inline constexpr u32 Heliotrope_gray = 0xaa98a9;
            /// @brief Neon fuchsia rgb(254, 65, 100)
            inline constexpr u32 Neon_fuchsia = 0xfe4164;
            /// @brief French rose rgb(246, 74, 138)
            inline constexpr u32 French_rose = 0xf64a8a;
            /// @brief United Nations blue rgb(91, 146, 229)
            inline constexpr u32 United_Nations_blue = 0x5b92e5;
            /// @brief Earth yellow rgb(225, 169, 95)
            inline constexpr u32 Earth_yellow = 0xe1a95f;
            /// @brief Sky magenta rgb(207, 113, 175)
            inline constexpr u32 Sky_magenta = 0xcf71af;
            /// @brief Old rose rgb(192, 128, 129)
            inline constexpr u32 Old_rose = 0xc08081;
            /// @brief Royal orange rgb(249, 146, 69)
            inline constexpr u32 Royal_orange = 0xf99245;
            /// @brief Terra cotta rgb(226, 114, 91)
            inline constexpr u32 Terra_cotta = 0xe2725b;
            /// @brief French fuchsia rgb(253, 63, 146)
            inline constexpr u32 French_fuchsia = 0xfd3f92;
            /// @brief Mandarin rgb(243, 122, 72)
            inline constexpr u32 Mandarin = 0xf37a48;
            /// @brief Maximum yellow red rgb(242, 186, 73)
            inline constexpr u32 Maximum_yellow_red = 0xf2ba49;
            /// @brief Maize (Crayola) rgb(242, 198, 73)
            inline constexpr u32 Maize_Crayola = 0xf2c649;
            /// @brief Burnt sienna rgb(233, 116, 81)
            inline constexpr u32 Burnt_sienna = 0xe97451;
            /// @brief Light red ochre rgb(233, 116, 81)
            inline constexpr u32 Light_red_ochre = 0xe97451;
            /// @brief Indian yellow rgb(227, 168, 87)
            inline constexpr u32 Indian_yellow = 0xe3a857;
            /// @brief Sunray rgb(227, 171, 87)
            inline constexpr u32 Sunray = 0xe3ab57;
            /// @brief Lanzones rgb(224, 188, 91)
            inline constexpr u32 Lanzones = 0xe0bc5b;
            /// @brief Blush rgb(222, 93, 131)
            inline constexpr u32 Blush = 0xde5d83;
            /// @brief Rich lavender rgb(167, 107, 207)
            inline constexpr u32 Rich_lavender = 0xa76bcf;
            /// @brief Super pink rgb(207, 107, 169)
            inline constexpr u32 Super_pink = 0xcf6ba9;
            /// @brief Pale taupe rgb(188, 152, 126)
            inline constexpr u32 Pale_taupe = 0xbc987e;
            /// @brief Opera mauve rgb(183, 132, 167)
            inline constexpr u32 Opera_mauve = 0xb784a7;
            /// @brief Rich lilac rgb(182, 102, 210)
            inline constexpr u32 Rich_lilac = 0xb666d2;
            /// @brief Cool grey rgb(140, 146, 172)
            inline constexpr u32 Cool_grey = 0x8c92ac;
            /// @brief Outrageous orange rgb(255, 96, 55)
            inline constexpr u32 Outrageous_orange = 0xff6037;
            /// @brief Orange (Crayola) rgb(255, 117, 56)
            inline constexpr u32 Orange_Crayola = 0xff7538;
            /// @brief Sizzling Red rgb(255, 56, 85)
            inline constexpr u32 Sizzling_Red = 0xff3855;
            /// @brief Red Salsa rgb(253, 58, 74)
            inline constexpr u32 Red_Salsa = 0xfd3a4a;
            /// @brief Orange Soda rgb(250, 91, 61)
            inline constexpr u32 Orange_Soda = 0xfa5b3d;
            /// @brief Ultramarine blue rgb(65, 102, 245)
            inline constexpr u32 Ultramarine_blue = 0x4166f5;
            /// @brief Maximum Green Yellow rgb(217, 230, 80)
            inline constexpr u32 Maximum_Green_Yellow = 0xd9e650;
            /// @brief Blizzard blue rgb(80, 191, 230)
            inline constexpr u32 Blizzard_blue = 0x50bfe6;
            /// @brief Violet-blue (Crayola) rgb(118, 110, 200)
            inline constexpr u32 Violet_blue_Crayola = 0x766ec8;
            /// @brief Pistachio rgb(147, 197, 114)
            inline constexpr u32 Pistachio = 0x93c572;
            /// @brief English lavender rgb(180, 131, 149)
            inline constexpr u32 English_lavender = 0xb48395;
            /// @brief Portland Orange rgb(255, 90, 54)
            inline constexpr u32 Portland_Orange = 0xff5a36;
            /// @brief French lime rgb(158, 253, 56)
            inline constexpr u32 French_lime = 0x9efd38;
            /// @brief Moonstone blue rgb(115, 169, 194)
            inline constexpr u32 Moonstone_blue = 0x73a9c2;
            /// @brief Radical Red rgb(255, 53, 94)
            inline constexpr u32 Radical_Red = 0xff355e;
            /// @brief Fire opal rgb(233, 92, 75)
            inline constexpr u32 Fire_opal = 0xe95c4b;
            /// @brief Blue-gray rgb(102, 153, 204)
            inline constexpr u32 Blue_gray = 0x6699cc;
            /// @brief Livid rgb(102, 153, 204)
            inline constexpr u32 Livid = 0x6699cc;
            /// @brief Amethyst rgb(153, 102, 204)
            inline constexpr u32 Amethyst = 0x9966cc;
            /// @brief Air superiority blue rgb(114, 160, 193)
            inline constexpr u32 Air_superiority_blue = 0x72a0c1;
            /// @brief Sunglow rgb(255, 204, 51)
            inline constexpr u32 Sunglow = 0xffcc33;
            /// @brief Razzle Dazzle Rose rgb(255, 51, 204)
            inline constexpr u32 Razzle_Dazzle_Rose = 0xff33cc;
            /// @brief Yellow (RYB) rgb(254, 254, 51)
            inline constexpr u32 Yellow_RYB = 0xfefe33;
            /// @brief Neon pink rgb(254, 52, 126)
            inline constexpr u32 Neon_pink = 0xfe347e;
            /// @brief Maximum yellow rgb(250, 250, 55)
            inline constexpr u32 Maximum_yellow = 0xfafa37;
            /// @brief June bud rgb(189, 218, 87)
            inline constexpr u32 June_bud = 0xbdda57;
            /// @brief Persian orange rgb(217, 144, 88)
            inline constexpr u32 Persian_orange = 0xd99058;
            /// @brief Misty Moss rgb(187, 180, 119)
            inline constexpr u32 Misty_Moss = 0xbbb477;
            /// @brief Lavender purple rgb(150, 123, 182)
            inline constexpr u32 Lavender_purple = 0x967bb6;
            /// @brief Fandango pink rgb(222, 82, 133)
            inline constexpr u32 Fandango_pink = 0xde5285;
            /// @brief Raw Sienna rgb(214, 138, 89)
            inline constexpr u32 Raw_Sienna = 0xd68a59;
            /// @brief Cerulean frost rgb(109, 155, 195)
            inline constexpr u32 Cerulean_frost = 0x6d9bc3;
            /// @brief Middle blue purple rgb(139, 114, 190)
            inline constexpr u32 Middle_blue_purple = 0x8b72be;
            /// @brief Grullo rgb(169, 154, 134)
            inline constexpr u32 Grullo = 0xa99a86;
            /// @brief Morning blue rgb(141, 163, 153)
            inline constexpr u32 Morning_blue = 0x8da399;
            /// @brief Spanish gray rgb(152, 152, 152)
            inline constexpr u32 Spanish_gray = 0x989898;
            /// @brief Green-yellow rgb(173, 255, 47)
            inline constexpr u32 Green_yellow = 0xadff2f;
            /// @brief Picton blue rgb(69, 177, 232)
            inline constexpr u32 Picton_blue = 0x45b1e8;
            /// @brief Cinnamon Satin rgb(205, 96, 126)
            inline constexpr u32 Cinnamon_Satin = 0xcd607e;
            /// @brief Purple mountain majesty rgb(150, 120, 182)
            inline constexpr u32 Purple_mountain_majesty = 0x9678b6;
            /// @brief Majorelle Blue rgb(96, 80, 220)
            inline constexpr u32 Majorelle_Blue = 0x6050dc;
            /// @brief Camel rgb(193, 154, 107)
            inline constexpr u32 Camel = 0xc19a6b;
            /// @brief Desert rgb(193, 154, 107)
            inline constexpr u32 Desert = 0xc19a6b;
            /// @brief Fallow rgb(193, 154, 107)
            inline constexpr u32 Fallow = 0xc19a6b;
            /// @brief Lion rgb(193, 154, 107)
            inline constexpr u32 Lion = 0xc19a6b;
            /// @brief Wood brown rgb(193, 154, 107)
            inline constexpr u32 Wood_brown = 0xc19a6b;
            /// @brief Olivine rgb(154, 185, 115)
            inline constexpr u32 Olivine = 0x9ab973;
            /// @brief Spring Frost rgb(135, 255, 42)
            inline constexpr u32 Spring_Frost = 0x87ff2a;
            /// @brief Mystic rgb(214, 82, 130)
            inline constexpr u32 Mystic = 0xd65282;
            /// @brief Carolina blue rgb(86, 160, 211)
            inline constexpr u32 Carolina_blue = 0x56a0d3;
            /// @brief Indian red rgb(205, 92, 92)
            inline constexpr u32 Indian_red = 0xcd5c5c;
            /// @brief Dark khaki rgb(189, 183, 107)
            inline constexpr u32 Dark_khaki = 0xbdb76b;
            /// @brief Green Lizard rgb(167, 244, 50)
            inline constexpr u32 Green_Lizard = 0xa7f432;
            /// @brief Medium orchid rgb(186, 85, 211)
            inline constexpr u32 Medium_orchid = 0xba55d3;
            /// @brief Slate blue rgb(106, 90, 205)
            inline constexpr u32 Slate_blue = 0x6a5acd;
            /// @brief Mantis rgb(116, 195, 101)
            inline constexpr u32 Mantis = 0x74c365;
            /// @brief Turkish rose rgb(181, 114, 129)
            inline constexpr u32 Turkish_rose = 0xb57281;
            /// @brief Persian rose rgb(254, 40, 162)
            inline constexpr u32 Persian_rose = 0xfe28a2;
            /// @brief Ripe mango rgb(255, 195, 36)
            inline constexpr u32 Ripe_mango = 0xffc324;
            /// @brief Saffron rgb(244, 196, 48)
            inline constexpr u32 Saffron = 0xf4c430;
            /// @brief Bluetiful rgb(60, 105, 231)
            inline constexpr u32 Bluetiful = 0x3c69e7;
            /// @brief Paradise pink rgb(230, 62, 98)
            inline constexpr u32 Paradise_pink = 0xe63e62;
            /// @brief Royal blue rgb(65, 105, 225)
            inline constexpr u32 Royal_blue = 0x4169e1;
            /// @brief Xanthous rgb(241, 180, 47)
            inline constexpr u32 Xanthous = 0xf1b42f;
            /// @brief Frostbite rgb(233, 54, 167)
            inline constexpr u32 Frostbite = 0xe936a7;
            /// @brief Royal pink rgb(231, 56, 149)
            inline constexpr u32 Royal_pink = 0xe73895;
            /// @brief Turquoise rgb(64, 224, 208)
            inline constexpr u32 Turquoise = 0x40e0d0;
            /// @brief Pink (Pantone) rgb(215, 72, 148)
            inline constexpr u32 Pink_Pantone = 0xd74894;
            /// @brief Middle green yellow rgb(172, 191, 96)
            inline constexpr u32 Middle_green_yellow = 0xacbf60;
            /// @brief Pearly purple rgb(183, 104, 162)
            inline constexpr u32 Pearly_purple = 0xb768a2;
            /// @brief Red-orange (Crayola) rgb(255, 104, 31)
            inline constexpr u32 Red_orange_Crayola = 0xff681f;
            /// @brief Dodger blue rgb(30, 144, 255)
            inline constexpr u32 Dodger_blue = 0x1e90ff;
            /// @brief Blue (Crayola) rgb(31, 117, 254)
            inline constexpr u32 Blue_Crayola = 0x1f75fe;
            /// @brief Iris rgb(90, 79, 207)
            inline constexpr u32 Iris = 0x5a4fcf;
            /// @brief Vegas gold rgb(197, 179, 88)
            inline constexpr u32 Vegas_gold = 0xc5b358;
            /// @brief Bright yellow (Crayola) rgb(255, 170, 29)
            inline constexpr u32 Bright_yellow_Crayola = 0xffaa1d;
            /// @brief Watermelon Yellow rgb(238, 255, 27)
            inline constexpr u32 Watermelon_Yellow = 0xeeff1b;
            /// @brief Hot magenta rgb(255, 29, 206)
            inline constexpr u32 Hot_magenta = 0xff1dce;
            /// @brief Princeton orange rgb(245, 128, 37)
            inline constexpr u32 Princeton_orange = 0xf58025;
            /// @brief Cadmium orange rgb(237, 135, 45)
            inline constexpr u32 Cadmium_orange = 0xed872d;
            /// @brief Tiger's eye rgb(224, 141, 60)
            inline constexpr u32 Tiger_s_eye = 0xe08d3c;
            /// @brief Tufts blue rgb(62, 142, 222)
            inline constexpr u32 Tufts_blue = 0x3e8ede;
            /// @brief Eucalyptus rgb(68, 215, 168)
            inline constexpr u32 Eucalyptus = 0x44d7a8;
            /// @brief Copper red rgb(203, 109, 81)
            inline constexpr u32 Copper_red = 0xcb6d51;
            /// @brief Green Sheen rgb(110, 174, 161)
            inline constexpr u32 Green_Sheen = 0x6eaea1;
            /// @brief Shadow blue rgb(119, 139, 165)
            inline constexpr u32 Shadow_blue = 0x778ba5;
            /// @brief Bleu de France rgb(49, 140, 231)
            inline constexpr u32 Bleu_de_France = 0x318ce7;
            /// @brief Android green rgb(61, 220, 132)
            inline constexpr u32 Android_green = 0x3ddc84;
            /// @brief Medium turquoise rgb(72, 209, 204)
            inline constexpr u32 Medium_turquoise = 0x48d1cc;
            /// @brief Emerald rgb(80, 200, 120)
            inline constexpr u32 Emerald = 0x50c878;
            /// @brief Paris Green rgb(80, 200, 120)
            inline constexpr u32 Paris_Green = 0x50c878;
            /// @brief Mulberry (Crayola) rgb(200, 80, 155)
            inline constexpr u32 Mulberry_Crayola = 0xc8509b;
            /// @brief Roman silver rgb(131, 137, 150)
            inline constexpr u32 Roman_silver = 0x838996;
            /// @brief Philippine gray rgb(140, 140, 140)
            inline constexpr u32 Philippine_gray = 0x8c8c8c;
            /// @brief Neon red rgb(255, 24, 24)
            inline constexpr u32 Neon_red = 0xff1818;
            /// @brief Pumpkin rgb(255, 117, 24)
            inline constexpr u32 Pumpkin = 0xff7518;
            /// @brief Vivid tangelo rgb(240, 116, 39)
            inline constexpr u32 Vivid_tangelo = 0xf07427;
            /// @brief Imperial red rgb(237, 41, 57)
            inline constexpr u32 Imperial_red = 0xed2939;
            /// @brief Red (Pantone) rgb(237, 41, 57)
            inline constexpr u32 Red_Pantone = 0xed2939;
            /// @brief Vermilion rgb(227, 66, 52)
            inline constexpr u32 Vermilion = 0xe34234;
            /// @brief Silver Lake blue rgb(93, 137, 186)
            inline constexpr u32 Silver_Lake_blue = 0x5d89ba;
            /// @brief Glaucous rgb(96, 130, 182)
            inline constexpr u32 Glaucous = 0x6082b6;
            /// @brief Bud green rgb(123, 182, 97)
            inline constexpr u32 Bud_green = 0x7bb661;
            /// @brief Copper penny rgb(173, 111, 105)
            inline constexpr u32 Copper_penny = 0xad6f69;
            /// @brief Aztec gold rgb(195, 153, 83)
            inline constexpr u32 Aztec_gold = 0xc39953;
            /// @brief Deep fuchsia rgb(193, 84, 193)
            inline constexpr u32 Deep_fuchsia = 0xc154c1;
            /// @brief Fuchsia (Crayola) rgb(193, 84, 193)
            inline constexpr u32 Fuchsia_Crayola = 0xc154c1;
            /// @brief Burnished brown rgb(161, 122, 116)
            inline constexpr u32 Burnished_brown = 0xa17a74;
            /// @brief Arctic lime rgb(208, 255, 20)
            inline constexpr u32 Arctic_lime = 0xd0ff14;
            /// @brief Neon green rgb(57, 255, 20)
            inline constexpr u32 Neon_green = 0x39ff14;
            /// @brief Deep pink rgb(255, 20, 147)
            inline constexpr u32 Deep_pink = 0xff1493;
            /// @brief Philippine pink rgb(250, 26, 142)
            inline constexpr u32 Philippine_pink = 0xfa1a8e;
            /// @brief Orange-yellow rgb(245, 189, 31)
            inline constexpr u32 Orange_yellow = 0xf5bd1f;
            /// @brief Pear rgb(209, 226, 49)
            inline constexpr u32 Pear = 0xd1e231;
            /// @brief Medium vermilion rgb(217, 96, 59)
            inline constexpr u32 Medium_vermilion = 0xd9603b;
            /// @brief Han blue rgb(68, 108, 207)
            inline constexpr u32 Han_blue = 0x446ccf;
            /// @brief Maximum Blue rgb(71, 171, 204)
            inline constexpr u32 Maximum_Blue = 0x47abcc;
            /// @brief English vermillion rgb(204, 71, 75)
            inline constexpr u32 English_vermillion = 0xcc474b;
            /// @brief Mountbatten pink rgb(153, 122, 141)
            inline constexpr u32 Mountbatten_pink = 0x997a8d;
            /// @brief Cinereous rgb(152, 129, 123)
            inline constexpr u32 Cinereous = 0x98817b;
            /// @brief Lotion blue rgb(21, 242, 253)
            inline constexpr u32 Lotion_blue = 0x15f2fd;
            /// @brief Han purple rgb(82, 24, 250)
            inline constexpr u32 Han_purple = 0x5218fa;
            /// @brief Magenta (Pantone) rgb(208, 65, 126)
            inline constexpr u32 Magenta_Pantone = 0xd0417e;
            /// @brief Olive green rgb(181, 179, 92)
            inline constexpr u32 Olive_green = 0xb5b35c;
            /// @brief Red (RYB) rgb(254, 39, 18)
            inline constexpr u32 Red_RYB = 0xfe2712;
            /// @brief Orioles orange rgb(251, 79, 20)
            inline constexpr u32 Orioles_orange = 0xfb4f14;
            /// @brief Dandelion rgb(221, 247, 25)
            inline constexpr u32 Dandelion = 0xddf719;
            /// @brief Deep lemon rgb(245, 199, 26)
            inline constexpr u32 Deep_lemon = 0xf5c71a;
            /// @brief Microsoft red rgb(240, 78, 31)
            inline constexpr u32 Microsoft_red = 0xf04e1f;
            /// @brief Purple (X11) rgb(160, 32, 240)
            inline constexpr u32 Purple_X11 = 0xa020f0;
            /// @brief Veronica rgb(160, 32, 240)
            inline constexpr u32 Veronica = 0xa020f0;
            /// @brief Amaranth rgb(229, 43, 80)
            inline constexpr u32 Amaranth = 0xe52b50;
            /// @brief Cerise rgb(222, 49, 99)
            inline constexpr u32 Cerise = 0xde3163;
            /// @brief Mulberry rgb(197, 75, 140)
            inline constexpr u32 Mulberry = 0xc54b8c;
            /// @brief Beaver rgb(159, 129, 112)
            inline constexpr u32 Beaver = 0x9f8170;
            /// @brief Mummy's Tomb rgb(130, 142, 132)
            inline constexpr u32 Mummy_s_Tomb = 0x828e84;
            /// @brief Taupe gray rgb(139, 133, 137)
            inline constexpr u32 Taupe_gray = 0x8b8589;
            /// @brief Red (Crayola) rgb(238, 32, 77)
            inline constexpr u32 Red_Crayola = 0xee204d;
            /// @brief Carrot orange rgb(237, 145, 33)
            inline constexpr u32 Carrot_orange = 0xed9121;
            /// @brief Blue-violet rgb(138, 43, 226)
            inline constexpr u32 Blue_violet = 0x8a2be2;
            /// @brief Bittersweet shimmer rgb(191, 79, 81)
            inline constexpr u32 Bittersweet_shimmer = 0xbf4f51;
            /// @brief Mikado yellow rgb(255, 196, 12)
            inline constexpr u32 Mikado_yellow = 0xffc40c;
            /// @brief Metallic yellow rgb(253, 204, 13)
            inline constexpr u32 Metallic_yellow = 0xfdcc0d;
            /// @brief Scarlet (Crayola) rgb(253, 14, 53)
            inline constexpr u32 Scarlet_Crayola = 0xfd0e35;
            /// @brief Tractor red rgb(253, 14, 53)
            inline constexpr u32 Tractor_red = 0xfd0e35;
            /// @brief Shocking pink rgb(252, 15, 192)
            inline constexpr u32 Shocking_pink = 0xfc0fc0;
            /// @brief Jonquil rgb(244, 202, 22)
            inline constexpr u32 Jonquil = 0xf4ca16;
            /// @brief Marigold rgb(234, 162, 33)
            inline constexpr u32 Marigold = 0xeaa221;
            /// @brief Deep cerise rgb(218, 50, 135)
            inline constexpr u32 Deep_cerise = 0xda3287;
            /// @brief Gold (metallic) rgb(212, 175, 55)
            inline constexpr u32 Gold_metallic = 0xd4af37;
            /// @brief Old gold rgb(207, 181, 59)
            inline constexpr u32 Old_gold = 0xcfb53b;
            /// @brief Peru rgb(205, 133, 63)
            inline constexpr u32 Peru = 0xcd853f;
            /// @brief Brick red rgb(203, 65, 84)
            inline constexpr u32 Brick_red = 0xcb4154;
            /// @brief Fuchsia rose rgb(199, 67, 117)
            inline constexpr u32 Fuchsia_rose = 0xc74375;
            /// @brief Rhythm rgb(119, 118, 150)
            inline constexpr u32 Rhythm = 0x777696;
            /// @brief Middle grey rgb(139, 134, 128)
            inline constexpr u32 Middle_grey = 0x8b8680;
            /// @brief Fluorescent blue rgb(21, 244, 238)
            inline constexpr u32 Fluorescent_blue = 0x15f4ee;
            /// @brief Red (pigment) rgb(237, 28, 36)
            inline constexpr u32 Red_pigment = 0xed1c24;
            /// @brief Vivid vermilion rgb(229, 96, 36)
            inline constexpr u32 Vivid_vermilion = 0xe56024;
            /// @brief Palatinate blue rgb(39, 59, 226)
            inline constexpr u32 Palatinate_blue = 0x273be2;
            /// @brief Metallic gold rgb(211, 175, 55)
            inline constexpr u32 Metallic_gold = 0xd3af37;
            /// @brief Blast-off bronze rgb(165, 113, 100)
            inline constexpr u32 Blast_off_bronze = 0xa57164;
            /// @brief Rocket metallic rgb(138, 127, 128)
            inline constexpr u32 Rocket_metallic = 0x8a7f80;
            /// @brief Spanish yellow rgb(246, 181, 17)
            inline constexpr u32 Spanish_yellow = 0xf6b511;
            /// @brief Alizarin rgb(219, 45, 67)
            inline constexpr u32 Alizarin = 0xdb2d43;
            /// @brief Strawberry red rgb(200, 63, 73)
            inline constexpr u32 Strawberry_red = 0xc83f49;
            /// @brief Purple Plum rgb(156, 81, 182)
            inline constexpr u32 Purple_Plum = 0x9c51b6;
            /// @brief Oxley rgb(109, 154, 121)
            inline constexpr u32 Oxley = 0x6d9a79;
            /// @brief Titanium rgb(135, 134, 129)
            inline constexpr u32 Titanium = 0x878681;
            /// @brief Lust rgb(230, 32, 32)
            inline constexpr u32 Lust = 0xe62020;
            /// @brief Rusty red rgb(218, 44, 67)
            inline constexpr u32 Rusty_red = 0xda2c43;
            /// @brief Fuchsia purple rgb(204, 57, 123)
            inline constexpr u32 Fuchsia_purple = 0xcc397b;
            /// @brief Rackley rgb(93, 138, 168)
            inline constexpr u32 Rackley = 0x5d8aa8;
            /// @brief Forest green (Crayola) rgb(95, 167, 119)
            inline constexpr u32 Forest_green_Crayola = 0x5fa777;
            /// @brief Shiny shamrock rgb(95, 167, 120)
            inline constexpr u32 Shiny_shamrock = 0x5fa778;
            /// @brief Battleship grey rgb(132, 132, 130)
            inline constexpr u32 Battleship_grey = 0x848482;
            /// @brief Old silver rgb(132, 132, 130)
            inline constexpr u32 Old_silver = 0x848482;
            /// @brief Vivid red rgb(247, 13, 26)
            inline constexpr u32 Vivid_red = 0xf70d1a;
            /// @brief Flame rgb(226, 88, 34)
            inline constexpr u32 Flame = 0xe25822;
            /// @brief Vivid red-tangelo rgb(223, 97, 36)
            inline constexpr u32 Vivid_red_tangelo = 0xdf6124;
            /// @brief Twitter blue rgb(38, 167, 222)
            inline constexpr u32 Twitter_blue = 0x26a7de;
            /// @brief Telemagenta rgb(207, 52, 118)
            inline constexpr u32 Telemagenta = 0xcf3476;
            /// @brief Red-violet (Crayola) rgb(192, 68, 143)
            inline constexpr u32 Red_violet_Crayola = 0xc0448f;
            /// @brief Neon scarlet rgb(255, 38, 3)
            inline constexpr u32 Neon_scarlet = 0xff2603;
            /// @brief Medium orange rgb(255, 120, 2)
            inline constexpr u32 Medium_orange = 0xff7802;
            /// @brief Medium yellow rgb(255, 227, 2)
            inline constexpr u32 Medium_yellow = 0xffe302;
            /// @brief Vivid yellow rgb(255, 227, 2)
            inline constexpr u32 Vivid_yellow = 0xffe302;
            /// @brief Urobilin rgb(225, 173, 33)
            inline constexpr u32 Urobilin = 0xe1ad21;
            /// @brief Barbie pink rgb(224, 33, 138)
            inline constexpr u32 Barbie_pink = 0xe0218a;
            /// @brief Deep chestnut rgb(185, 78, 72)
            inline constexpr u32 Deep_chestnut = 0xb94e48;
            /// @brief Café au lait rgb(166, 123, 91)
            inline constexpr u32 Café_au_lait = 0xa67b5b;
            /// @brief French beige rgb(166, 123, 91)
            inline constexpr u32 French_beige = 0xa67b5b;
            /// @brief Tuscan tan rgb(166, 123, 91)
            inline constexpr u32 Tuscan_tan = 0xa67b5b;
            /// @brief Polished pine rgb(93, 164, 147)
            inline constexpr u32 Polished_pine = 0x5da493;
            /// @brief Red rgb(255, 0, 0)
            inline constexpr u32 Red = 0xff0000;
            /// @brief Candy apple red rgb(255, 8, 0)
            inline constexpr u32 Candy_apple_red = 0xff0800;
            /// @brief Scarlet rgb(255, 36, 0)
            inline constexpr u32 Scarlet = 0xff2400;
            /// @brief Coquelicot rgb(255, 56, 0)
            inline constexpr u32 Coquelicot = 0xff3800;
            /// @brief Red-orange (Color wheel) rgb(255, 69, 0)
            inline constexpr u32 Red_orange_Color_wheel = 0xff4500;
            /// @brief International orange (aerospace) rgb(255, 79, 0)
            inline constexpr u32 International_orange_aerospace = 0xff4f00;
            /// @brief Mystic red rgb(255, 85, 0)
            inline constexpr u32 Mystic_red = 0xff5500;
            /// @brief Orange (Pantone) rgb(255, 88, 0)
            inline constexpr u32 Orange_Pantone = 0xff5800;
            /// @brief Maximum orange rgb(255, 91, 0)
            inline constexpr u32 Maximum_orange = 0xff5b00;
            /// @brief Vivid orange rgb(255, 95, 0)
            inline constexpr u32 Vivid_orange = 0xff5f00;
            /// @brief Orange rgb(255, 102, 0)
            inline constexpr u32 Orange = 0xff6600;
            /// @brief Orange iced tea rgb(255, 103, 0)
            inline constexpr u32 Orange_iced_tea = 0xff6700;
            /// @brief Safety orange (blaze orange) rgb(255, 103, 0)
            inline constexpr u32 Safety_orange_blaze_orange = 0xff6700;
            /// @brief Philippine orange rgb(255, 115, 0)
            inline constexpr u32 Philippine_orange = 0xff7300;
            /// @brief Heat Wave rgb(255, 122, 0)
            inline constexpr u32 Heat_Wave = 0xff7a00;
            /// @brief Safety orange rgb(255, 120, 0)
            inline constexpr u32 Safety_orange = 0xff7800;
            /// @brief Amber (SAE/ECE) rgb(255, 126, 0)
            inline constexpr u32 Amber_SAE_ECE = 0xff7e00;
            /// @brief Orange (color wheel) rgb(255, 127, 0)
            inline constexpr u32 Orange_color_wheel = 0xff7f00;
            /// @brief Dark orange rgb(255, 140, 0)
            inline constexpr u32 Dark_orange = 0xff8c00;
            /// @brief Vivid gamboge rgb(255, 153, 0)
            inline constexpr u32 Vivid_gamboge = 0xff9900;
            /// @brief Vivid orange peel rgb(255, 160, 0)
            inline constexpr u32 Vivid_orange_peel = 0xffa000;
            /// @brief Orange (web) rgb(255, 165, 0)
            inline constexpr u32 Orange_web = 0xffa500;
            /// @brief Amber rgb(255, 191, 0)
            inline constexpr u32 Amber = 0xffbf00;
            /// @brief Selective yellow rgb(255, 186, 0)
            inline constexpr u32 Selective_yellow = 0xffba00;
            /// @brief Tangerine yellow rgb(255, 204, 0)
            inline constexpr u32 Tangerine_yellow = 0xffcc00;
            /// @brief Cyber yellow rgb(255, 211, 0)
            inline constexpr u32 Cyber_yellow = 0xffd300;
            /// @brief Gold (web) (Golden) rgb(255, 215, 0)
            inline constexpr u32 Gold_web_Golden = 0xffd700;
            /// @brief Yellow (NCS) rgb(255, 211, 0)
            inline constexpr u32 Yellow_NCS = 0xffd300;
            /// @brief School bus yellow rgb(255, 216, 0)
            inline constexpr u32 School_bus_yellow = 0xffd800;
            /// @brief Sizzling Sunrise rgb(255, 219, 0)
            inline constexpr u32 Sizzling_Sunrise = 0xffdb00;
            /// @brief Golden yellow rgb(255, 223, 0)
            inline constexpr u32 Golden_yellow = 0xffdf00;
            /// @brief Philippine golden yellow rgb(255, 223, 0)
            inline constexpr u32 Philippine_golden_yellow = 0xffdf00;
            /// @brief Canary yellow rgb(255, 239, 0)
            inline constexpr u32 Canary_yellow = 0xffef00;
            /// @brief Middle yellow rgb(255, 235, 0)
            inline constexpr u32 Middle_yellow = 0xffeb00;
            /// @brief Yellow (process) rgb(255, 239, 0)
            inline constexpr u32 Yellow_process = 0xffef00;
            /// @brief Yellow rose rgb(255, 240, 0)
            inline constexpr u32 Yellow_rose = 0xfff000;
            /// @brief Cadmium yellow rgb(255, 246, 0)
            inline constexpr u32 Cadmium_yellow = 0xfff600;
            /// @brief Lemon rgb(255, 247, 0)
            inline constexpr u32 Lemon = 0xfff700;
            /// @brief Neon yellow rgb(255, 247, 0)
            inline constexpr u32 Neon_yellow = 0xfff700;
            /// @brief Yellow Sunshine rgb(255, 247, 0)
            inline constexpr u32 Yellow_Sunshine = 0xfff700;
            /// @brief Lemon glacier rgb(253, 255, 0)
            inline constexpr u32 Lemon_glacier = 0xfdff00;
            /// @brief Yellow rgb(255, 255, 0)
            inline constexpr u32 Yellow = 0xffff00;
            /// @brief Lemon lime rgb(227, 255, 0)
            inline constexpr u32 Lemon_lime = 0xe3ff00;
            /// @brief Electric lime rgb(204, 255, 0)
            inline constexpr u32 Electric_lime = 0xccff00;
            /// @brief Lime (color wheel) rgb(191, 255, 0)
            inline constexpr u32 Lime_color_wheel = 0xbfff00;
            /// @brief Mango green rgb(150, 255, 0)
            inline constexpr u32 Mango_green = 0x96ff00;
            /// @brief Chartreuse rgb(127, 255, 0)
            inline constexpr u32 Chartreuse = 0x7fff00;
            /// @brief Bright green rgb(102, 255, 0)
            inline constexpr u32 Bright_green = 0x66ff00;
            /// @brief Harlequin rgb(63, 255, 0)
            inline constexpr u32 Harlequin = 0x3fff00;
            /// @brief Green rgb(0, 255, 0)
            inline constexpr u32 Green = 0x00ff00;
            /// @brief Lime (web) (X11 green) rgb(0, 255, 0)
            inline constexpr u32 Lime_web_X11_green = 0x00ff00;
            /// @brief Spring green rgb(0, 255, 127)
            inline constexpr u32 Spring_green = 0x00ff7f;
            /// @brief Sea green (Crayola) rgb(0, 255, 205)
            inline constexpr u32 Sea_green_Crayola = 0x00ffcd;
            /// @brief Aqua rgb(0, 255, 255)
            inline constexpr u32 Aqua = 0x00ffff;
            /// @brief Cyan rgb(0, 255, 255)
            inline constexpr u32 Cyan = 0x00ffff;
            /// @brief Spanish sky blue rgb(0, 255, 255)
            inline constexpr u32 Spanish_sky_blue = 0x00ffff;
            /// @brief Deep sky blue rgb(0, 191, 255)
            inline constexpr u32 Deep_sky_blue = 0x00bfff;
            /// @brief Azure rgb(0, 127, 255)
            inline constexpr u32 Azure = 0x007fff;
            /// @brief Philippine sky blue rgb(0, 102, 255)
            inline constexpr u32 Philippine_sky_blue = 0x0066ff;
            /// @brief Blue rgb(0, 0, 255)
            inline constexpr u32 Blue = 0x0000ff;
            /// @brief Indigo (color wheel) rgb(64, 0, 255)
            inline constexpr u32 Indigo_color_wheel = 0x4000ff;
            /// @brief Ultramarine rgb(63, 0, 255)
            inline constexpr u32 Ultramarine = 0x3f00ff;
            /// @brief Electric indigo rgb(111, 0, 255)
            inline constexpr u32 Electric_indigo = 0x6f00ff;
            /// @brief Violet (color wheel) rgb(127, 0, 255)
            inline constexpr u32 Violet_color_wheel = 0x7f00ff;
            /// @brief Electric violet rgb(143, 0, 255)
            inline constexpr u32 Electric_violet = 0x8f00ff;
            /// @brief Violet rgb(143, 0, 255)
            inline constexpr u32 Violet = 0x8f00ff;
            /// @brief Vivid violet rgb(159, 0, 255)
            inline constexpr u32 Vivid_violet = 0x9f00ff;
            /// @brief Electric purple rgb(191, 0, 255)
            inline constexpr u32 Electric_purple = 0xbf00ff;
            /// @brief Vivid orchid rgb(204, 0, 255)
            inline constexpr u32 Vivid_orchid = 0xcc00ff;
            /// @brief Phlox rgb(223, 0, 255)
            inline constexpr u32 Phlox = 0xdf00ff;
            /// @brief Psychedelic purple rgb(223, 0, 255)
            inline constexpr u32 Psychedelic_purple = 0xdf00ff;
            /// @brief Fuchsia rgb(255, 0, 255)
            inline constexpr u32 Fuchsia = 0xff00ff;
            /// @brief Magenta rgb(255, 0, 255)
            inline constexpr u32 Magenta = 0xff00ff;
            /// @brief Hot fuchsia rgb(255, 0, 198)
            inline constexpr u32 Hot_fuchsia = 0xff00c6;
            /// @brief Bright pink rgb(255, 0, 127)
            inline constexpr u32 Bright_pink = 0xff007f;
            /// @brief Rose rgb(255, 0, 127)
            inline constexpr u32 Rose = 0xff007f;
            /// @brief Winter Sky rgb(255, 0, 124)
            inline constexpr u32 Winter_Sky = 0xff007c;
            /// @brief Vivid raspberry rgb(255, 0, 108)
            inline constexpr u32 Vivid_raspberry = 0xff006c;
            /// @brief Poison Purple rgb(127, 1, 254)
            inline constexpr u32 Poison_Purple = 0x7f01fe;
            /// @brief Mango rgb(253, 190, 2)
            inline constexpr u32 Mango = 0xfdbe02;
            /// @brief Neon tangerine rgb(246, 137, 10)
            inline constexpr u32 Neon_tangerine = 0xf6890a;
            /// @brief Ultramarine blue (Caran d'Ache) rgb(33, 17, 239)
            inline constexpr u32 Ultramarine_blue_Caran_d_Ache = 0x2111ef;
            /// @brief Spanish crimson rgb(229, 26, 76)
            inline constexpr u32 Spanish_crimson = 0xe51a4c;
            /// @brief Bronze rgb(205, 127, 50)
            inline constexpr u32 Bronze = 0xcd7f32;
            /// @brief Yellow-green rgb(154, 205, 50)
            inline constexpr u32 Yellow_green = 0x9acd32;
            /// @brief Lime green rgb(50, 205, 50)
            inline constexpr u32 Lime_green = 0x32cd32;
            /// @brief Persian red rgb(204, 51, 51)
            inline constexpr u32 Persian_red = 0xcc3333;
            /// @brief Steel pink rgb(204, 51, 204)
            inline constexpr u32 Steel_pink = 0xcc33cc;
            /// @brief Madder Lake rgb(204, 51, 54)
            inline constexpr u32 Madder_Lake = 0xcc3336;
            /// @brief Satin sheen gold rgb(203, 161, 53)
            inline constexpr u32 Satin_sheen_gold = 0xcba135;
            /// @brief Watermelon red rgb(191, 65, 71)
            inline constexpr u32 Watermelon_red = 0xbf4147;
            /// @brief Cadet blue rgb(95, 158, 160)
            inline constexpr u32 Cadet_blue = 0x5f9ea0;
            /// @brief Copper rose rgb(153, 102, 102)
            inline constexpr u32 Copper_rose = 0x996666;
            /// @brief Dark blue-gray rgb(102, 102, 153)
            inline constexpr u32 Dark_blue_gray = 0x666699;
            /// @brief Slate gray rgb(112, 128, 144)
            inline constexpr u32 Slate_gray = 0x708090;
            /// @brief Gray (web) rgb(128, 128, 128)
            inline constexpr u32 Gray_web = 0x808080;
            /// @brief Neon gray rgb(128, 128, 128)
            inline constexpr u32 Neon_gray = 0x808080;
            /// @brief Trolley grey rgb(128, 128, 128)
            inline constexpr u32 Trolley_grey = 0x808080;
            /// @brief Willpower orange rgb(253, 88, 0)
            inline constexpr u32 Willpower_orange = 0xfd5800;
            /// @brief Microsoft yellow rgb(253, 185, 0)
            inline constexpr u32 Microsoft_yellow = 0xfdb900;
            /// @brief Philippine yellow rgb(254, 203, 0)
            inline constexpr u32 Philippine_yellow = 0xfecb00;
            /// @brief Yellow (Pantone) rgb(254, 223, 0)
            inline constexpr u32 Yellow_Pantone = 0xfedf00;
            /// @brief Aureolin rgb(253, 238, 0)
            inline constexpr u32 Aureolin = 0xfdee00;
            /// @brief Neon cyan rgb(0, 254, 252)
            inline constexpr u32 Neon_cyan = 0x00fefc;
            /// @brief Orange (RYB) rgb(251, 153, 2)
            inline constexpr u32 Orange_RYB = 0xfb9902;
            /// @brief Dark orchid rgb(153, 50, 204)
            inline constexpr u32 Dark_orchid = 0x9932cc;
            /// @brief Cedar Chest rgb(202, 52, 53)
            inline constexpr u32 Cedar_Chest = 0xca3435;
            /// @brief Golden poppy rgb(252, 194, 0)
            inline constexpr u32 Golden_poppy = 0xfcc200;
            /// @brief Spring bud rgb(167, 252, 0)
            inline constexpr u32 Spring_bud = 0xa7fc00;
            /// @brief Orange soda rgb(231, 78, 20)
            inline constexpr u32 Orange_soda = 0xe74e14;
            /// @brief Moonstone rgb(58, 168, 193)
            inline constexpr u32 Moonstone = 0x3aa8c1;
            /// @brief Brown sugar rgb(175, 110, 77)
            inline constexpr u32 Brown_sugar = 0xaf6e4d;
            /// @brief Purpureus rgb(154, 78, 174)
            inline constexpr u32 Purpureus = 0x9a4eae;
            /// @brief Asparagus rgb(123, 160, 91)
            inline constexpr u32 Asparagus = 0x7ba05b;
            /// @brief Rose dust rgb(158, 94, 111)
            inline constexpr u32 Rose_dust = 0x9e5e6f;
            /// @brief Tangelo rgb(249, 77, 0)
            inline constexpr u32 Tangelo = 0xf94d00;
            /// @brief Medium spring green rgb(0, 250, 154)
            inline constexpr u32 Medium_spring_green = 0x00fa9a;
            /// @brief Goldenrod rgb(218, 165, 32)
            inline constexpr u32 Goldenrod = 0xdaa520;
            /// @brief Maximum red rgb(217, 33, 33)
            inline constexpr u32 Maximum_red = 0xd92121;
            /// @brief Steel blue rgb(70, 130, 180)
            inline constexpr u32 Steel_blue = 0x4682b4;
            /// @brief Royal purple rgb(120, 81, 169)
            inline constexpr u32 Royal_purple = 0x7851a9;
            /// @brief Amethyst (Crayola) rgb(100, 96, 154)
            inline constexpr u32 Amethyst_Crayola = 0x64609a;
            /// @brief Russian green rgb(103, 146, 103)
            inline constexpr u32 Russian_green = 0x679267;
            /// @brief Xanadu rgb(115, 134, 120)
            inline constexpr u32 Xanadu = 0x738678;
            /// @brief Xanthic rgb(238, 237, 9)
            inline constexpr u32 Xanthic = 0xeeed09;
            /// @brief Vivid cerise rgb(218, 29, 129)
            inline constexpr u32 Vivid_cerise = 0xda1d81;
            /// @brief Vermilion rgb(217, 56, 30)
            inline constexpr u32 Vermilion = 0xd9381e;
            /// @brief Dingy Dungeon rgb(197, 49, 81)
            inline constexpr u32 Dingy_Dungeon = 0xc53151;
            /// @brief Irresistible rgb(179, 68, 108)
            inline constexpr u32 Irresistible = 0xb3446c;
            /// @brief Plump Purple rgb(89, 70, 178)
            inline constexpr u32 Plump_Purple = 0x5946b2;
            /// @brief Blue yonder rgb(80, 114, 167)
            inline constexpr u32 Blue_yonder = 0x5072a7;
            /// @brief Middle red purple rgb(165, 83, 83)
            inline constexpr u32 Middle_red_purple = 0xa55353;
            /// @brief Redwood rgb(164, 90, 82)
            inline constexpr u32 Redwood = 0xa45a52;
            /// @brief Fashion fuchsia rgb(244, 0, 161)
            inline constexpr u32 Fashion_fuchsia = 0xf400a1;
            /// @brief Hollywood cerise rgb(244, 0, 161)
            inline constexpr u32 Hollywood_cerise = 0xf400a1;
            /// @brief Royal fuchsia rgb(202, 44, 146)
            inline constexpr u32 Royal_fuchsia = 0xca2c92;
            /// @brief Verdigris rgb(67, 179, 174)
            inline constexpr u32 Verdigris = 0x43b3ae;
            /// @brief English red rgb(171, 75, 82)
            inline constexpr u32 English_red = 0xab4b52;
            /// @brief Moss green rgb(138, 154, 91)
            inline constexpr u32 Moss_green = 0x8a9a5b;
            /// @brief Smoke rgb(115, 130, 118)
            inline constexpr u32 Smoke = 0x738276;
            /// @brief Gamboge rgb(228, 155, 15)
            inline constexpr u32 Gamboge = 0xe49b0f;
            /// @brief Cerulean (Crayola) rgb(29, 172, 214)
            inline constexpr u32 Cerulean_Crayola = 0x1dacd6;
            /// @brief French raspberry rgb(199, 44, 72)
            inline constexpr u32 French_raspberry = 0xc72c48;
            /// @brief Mint rgb(62, 180, 137)
            inline constexpr u32 Mint = 0x3eb489;
            /// @brief Tangerine rgb(242, 133, 0)
            inline constexpr u32 Tangerine = 0xf28500;
            /// @brief Red (Munsell) rgb(242, 0, 60)
            inline constexpr u32 Red_Munsell = 0xf2003c;
            /// @brief Ruby rgb(224, 17, 95)
            inline constexpr u32 Ruby = 0xe0115f;
            /// @brief Yellow (Munsell) rgb(239, 204, 0)
            inline constexpr u32 Yellow_Munsell = 0xefcc00;
            /// @brief Safety yellow rgb(238, 210, 2)
            inline constexpr u32 Safety_yellow = 0xeed202;
            /// @brief Red strawberry rgb(236, 3, 4)
            inline constexpr u32 Red_strawberry = 0xec0304;
            /// @brief Bright turquoise rgb(8, 232, 222)
            inline constexpr u32 Bright_turquoise = 0x08e8de;
            /// @brief Vivid mulberry rgb(184, 12, 227)
            inline constexpr u32 Vivid_mulberry = 0xb80ce3;
            /// @brief Crimson rgb(220, 20, 60)
            inline constexpr u32 Crimson = 0xdc143c;
            /// @brief Dogwood rose rgb(215, 24, 104)
            inline constexpr u32 Dogwood_rose = 0xd71868;
            /// @brief Chocolate (web) rgb(210, 105, 30)
            inline constexpr u32 Chocolate_web = 0xd2691e;
            /// @brief Cocoa brown rgb(210, 105, 30)
            inline constexpr u32 Cocoa_brown = 0xd2691e;
            /// @brief Green-blue (Crayola) rgb(40, 135, 200)
            inline constexpr u32 Green_blue_Crayola = 0x2887c8;
            /// @brief Maximum Blue Green rgb(48, 191, 191)
            inline constexpr u32 Maximum_Blue_Green = 0x30bfbf;
            /// @brief Byzantine rgb(189, 51, 164)
            inline constexpr u32 Byzantine = 0xbd33a4;
            /// @brief Medium sea green rgb(60, 179, 113)
            inline constexpr u32 Medium_sea_green = 0x3cb371;
            /// @brief Mystic maroon rgb(173, 67, 121)
            inline constexpr u32 Mystic_maroon = 0xad4379;
            /// @brief Mauve taupe rgb(145, 95, 109)
            inline constexpr u32 Mauve_taupe = 0x915f6d;
            /// @brief Titanium yellow rgb(238, 230, 0)
            inline constexpr u32 Titanium_yellow = 0xeee600;
            /// @brief Vivid cerulean rgb(0, 170, 238)
            inline constexpr u32 Vivid_cerulean = 0x00aaee;
            /// @brief Microsoft blue rgb(0, 162, 237)
            inline constexpr u32 Microsoft_blue = 0x00a2ed;
            /// @brief Citrine rgb(228, 208, 10)
            inline constexpr u32 Citrine = 0xe4d00a;
            /// @brief Raspberry rgb(227, 11, 93)
            inline constexpr u32 Raspberry = 0xe30b5d;
            /// @brief Razzmatazz rgb(227, 11, 92)
            inline constexpr u32 Razzmatazz = 0xe30b5c;
            /// @brief Bitter lemon rgb(202, 224, 13)
            inline constexpr u32 Bitter_lemon = 0xcae00d;
            /// @brief Fire engine red rgb(206, 32, 41)
            inline constexpr u32 Fire_engine_red = 0xce2029;
            /// @brief Ochre rgb(204, 119, 34)
            inline constexpr u32 Ochre = 0xcc7722;
            /// @brief Neon brown rgb(195, 115, 42)
            inline constexpr u32 Neon_brown = 0xc3732a;
            /// @brief Medium red-violet rgb(187, 51, 133)
            inline constexpr u32 Medium_red_violet = 0xbb3385;
            /// @brief Brown (crayola) rgb(175, 89, 62)
            inline constexpr u32 Brown_crayola = 0xaf593e;
            /// @brief Dirt rgb(155, 118, 83)
            inline constexpr u32 Dirt = 0x9b7653;
            /// @brief Liver chestnut rgb(152, 116, 86)
            inline constexpr u32 Liver_chestnut = 0x987456;
            /// @brief Antique fuchsia rgb(145, 92, 131)
            inline constexpr u32 Antique_fuchsia = 0x915c83;
            /// @brief Steel teal rgb(95, 138, 143)
            inline constexpr u32 Steel_teal = 0x5f8a8f;
            /// @brief French lilac rgb(134, 96, 142)
            inline constexpr u32 French_lilac = 0x86608e;
            /// @brief Pomp and Power rgb(134, 96, 142)
            inline constexpr u32 Pomp_and_Power = 0x86608e;
            /// @brief Persimmon rgb(236, 88, 0)
            inline constexpr u32 Persimmon = 0xec5800;
            /// @brief Bright navy blue rgb(25, 116, 210)
            inline constexpr u32 Bright_navy_blue = 0x1974d2;
            /// @brief Navy blue (Crayola) rgb(25, 116, 210)
            inline constexpr u32 Navy_blue_Crayola = 0x1974d2;
            /// @brief International orange (Golden Gate Bridge) rgb(192, 54, 44)
            inline constexpr u32 International_orange_Golden_Gate_Bridge = 0xc0362c;
            /// @brief Copper rgb(184, 115, 51)
            inline constexpr u32 Copper = 0xb87333;
            /// @brief Metallic bronze rgb(169, 113, 66)
            inline constexpr u32 Metallic_bronze = 0xa97142;
            /// @brief Pale brown rgb(152, 118, 84)
            inline constexpr u32 Pale_brown = 0x987654;
            /// @brief Metallic orange rgb(218, 104, 15)
            inline constexpr u32 Metallic_orange = 0xda680f;
            /// @brief Lemon curry rgb(204, 160, 29)
            inline constexpr u32 Lemon_curry = 0xcca01d;
            /// @brief Mountain Meadow rgb(48, 186, 143)
            inline constexpr u32 Mountain_Meadow = 0x30ba8f;
            /// @brief Keppel rgb(58, 176, 158)
            inline constexpr u32 Keppel = 0x3ab09e;
            /// @brief Medium ruby rgb(170, 64, 105)
            inline constexpr u32 Medium_ruby = 0xaa4069;
            /// @brief Sonic silver rgb(117, 117, 117)
            inline constexpr u32 Sonic_silver = 0x757575;
            /// @brief Spanish orange rgb(232, 97, 0)
            inline constexpr u32 Spanish_orange = 0xe86100;
            /// @brief Medium candy apple red rgb(226, 6, 44)
            inline constexpr u32 Medium_candy_apple_red = 0xe2062c;
            /// @brief New Car rgb(33, 79, 198)
            inline constexpr u32 New_Car = 0x214fc6;
            /// @brief Cerulean blue rgb(42, 82, 190)
            inline constexpr u32 Cerulean_blue = 0x2a52be;
            /// @brief Fandango rgb(181, 51, 137)
            inline constexpr u32 Fandango = 0xb53389;
            /// @brief Shadow rgb(138, 121, 93)
            inline constexpr u32 Shadow = 0x8a795d;
            /// @brief Chinese violet rgb(133, 96, 136)
            inline constexpr u32 Chinese_violet = 0x856088;
            /// @brief Peridot rgb(230, 226, 0)
            inline constexpr u32 Peridot = 0xe6e200;
            /// @brief Spanish red rgb(230, 0, 38)
            inline constexpr u32 Spanish_red = 0xe60026;
            /// @brief Malachite rgb(11, 218, 81)
            inline constexpr u32 Malachite = 0x0bda51;
            /// @brief Pacific Blue rgb(28, 169, 201)
            inline constexpr u32 Pacific_Blue = 0x1ca9c9;
            /// @brief Nickel rgb(114, 116, 114)
            inline constexpr u32 Nickel = 0x727472;
            /// @brief Fulvous rgb(228, 132, 0)
            inline constexpr u32 Fulvous = 0xe48400;
            /// @brief Mexican pink rgb(228, 0, 124)
            inline constexpr u32 Mexican_pink = 0xe4007c;
            /// @brief Cadmium red rgb(227, 0, 34)
            inline constexpr u32 Cadmium_red = 0xe30022;
            /// @brief Nintendo red rgb(228, 0, 15)
            inline constexpr u32 Nintendo_red = 0xe4000f;
            /// @brief Stop red rgb(207, 20, 43)
            inline constexpr u32 Stop_red = 0xcf142b;
            /// @brief Bright maroon rgb(195, 33, 72)
            inline constexpr u32 Bright_maroon = 0xc32148;
            /// @brief Maroon (Crayola) rgb(195, 33, 72)
            inline constexpr u32 Maroon_Crayola = 0xc32148;
            /// @brief Violet-blue rgb(50, 74, 178)
            inline constexpr u32 Violet_blue = 0x324ab2;
            /// @brief Medium carmine rgb(175, 64, 53)
            inline constexpr u32 Medium_carmine = 0xaf4035;
            /// @brief Pale carmine rgb(175, 64, 53)
            inline constexpr u32 Pale_carmine = 0xaf4035;
            /// @brief Mustard yellow rgb(225, 173, 1)
            inline constexpr u32 Mustard_yellow = 0xe1ad01;
            /// @brief Cardinal rgb(196, 30, 58)
            inline constexpr u32 Cardinal = 0xc41e3a;
            /// @brief Liver (dogs) rgb(184, 109, 41)
            inline constexpr u32 Liver_dogs = 0xb86d29;
            /// @brief Green (RYB) rgb(102, 176, 50)
            inline constexpr u32 Green_RYB = 0x66b032;
            /// @brief Dark tan rgb(145, 129, 81)
            inline constexpr u32 Dark_tan = 0x918151;
            /// @brief Old lavender rgb(121, 104, 120)
            inline constexpr u32 Old_lavender = 0x796878;
            /// @brief Red cola rgb(223, 1, 24)
            inline constexpr u32 Red_cola = 0xdf0118;
            /// @brief Lava rgb(207, 16, 32)
            inline constexpr u32 Lava = 0xcf1020;
            /// @brief Philippine red rgb(206, 17, 39)
            inline constexpr u32 Philippine_red = 0xce1127;
            /// @brief Maroon (X11) rgb(176, 48, 96)
            inline constexpr u32 Maroon_X11 = 0xb03060;
            /// @brief Rich maroon rgb(176, 48, 96)
            inline constexpr u32 Rich_maroon = 0xb03060;
            /// @brief Maximum Red Purple rgb(166, 58, 121)
            inline constexpr u32 Maximum_Red_Purple = 0xa63a79;
            /// @brief Sugar plum rgb(145, 78, 117)
            inline constexpr u32 Sugar_plum = 0x914e75;
            /// @brief Vivid lime green rgb(166, 214, 8)
            inline constexpr u32 Vivid_lime_green = 0xa6d608;
            /// @brief Wintergreen dream rgb(86, 136, 125)
            inline constexpr u32 Wintergreen_dream = 0x56887d;
            /// @brief Medium violet-red rgb(199, 21, 133)
            inline constexpr u32 Medium_violet_red = 0xc71585;
            /// @brief Red-violet rgb(199, 21, 133)
            inline constexpr u32 Red_violet = 0xc71585;
            /// @brief Razzmic Berry rgb(141, 78, 133)
            inline constexpr u32 Razzmic_Berry = 0x8d4e85;
            /// @brief Deep Taupe rgb(126, 94, 96)
            inline constexpr u32 Deep_Taupe = 0x7e5e60;
            /// @brief Harvest gold rgb(218, 145, 0)
            inline constexpr u32 Harvest_gold = 0xda9100;
            /// @brief Acid green rgb(176, 191, 26)
            inline constexpr u32 Acid_green = 0xb0bf1a;
            /// @brief Sweet Brown rgb(168, 55, 49)
            inline constexpr u32 Sweet_Brown = 0xa83731;
            /// @brief Rum rgb(154, 78, 64)
            inline constexpr u32 Rum = 0x9a4e40;
            /// @brief Middle green rgb(77, 140, 87)
            inline constexpr u32 Middle_green = 0x4d8c57;
            /// @brief Microsoft Edge blue rgb(0, 120, 215)
            inline constexpr u32 Microsoft_Edge_blue = 0x0078d7;
            /// @brief Rich carmine rgb(215, 0, 64)
            inline constexpr u32 Rich_carmine = 0xd70040;
            /// @brief Rich electric blue rgb(8, 146, 208)
            inline constexpr u32 Rich_electric_blue = 0x0892d0;
            /// @brief Persian blue rgb(28, 57, 187)
            inline constexpr u32 Persian_blue = 0x1c39bb;
            /// @brief Denim Blue rgb(34, 67, 182)
            inline constexpr u32 Denim_Blue = 0x2243b6;
            /// @brief Berry parfait rgb(164, 52, 130)
            inline constexpr u32 Berry_parfait = 0xa43482;
            /// @brief Queen blue rgb(67, 107, 149)
            inline constexpr u32 Queen_blue = 0x436b95;
            /// @brief Spicy mix rgb(139, 95, 77)
            inline constexpr u32 Spicy_mix = 0x8b5f4d;
            /// @brief Sheen green rgb(143, 212, 0)
            inline constexpr u32 Sheen_green = 0x8fd400;
            /// @brief French violet rgb(136, 6, 206)
            inline constexpr u32 French_violet = 0x8806ce;
            /// @brief Sinopia rgb(203, 65, 11)
            inline constexpr u32 Sinopia = 0xcb410b;
            /// @brief Alloy orange rgb(196, 98, 16)
            inline constexpr u32 Alloy_orange = 0xc46210;
            /// @brief Metallic Sunburst rgb(156, 124, 56)
            inline constexpr u32 Metallic_Sunburst = 0x9c7c38;
            /// @brief Coconut rgb(150, 90, 62)
            inline constexpr u32 Coconut = 0x965a3e;
            /// @brief Pastel brown rgb(131, 105, 83)
            inline constexpr u32 Pastel_brown = 0x836953;
            /// @brief Dark violet rgb(148, 0, 211)
            inline constexpr u32 Dark_violet = 0x9400d3;
            /// @brief Denim rgb(21, 96, 189)
            inline constexpr u32 Denim = 0x1560bd;
            /// @brief Light brown rgb(181, 101, 29)
            inline constexpr u32 Light_brown = 0xb5651d;
            /// @brief Firebrick rgb(178, 34, 34)
            inline constexpr u32 Firebrick = 0xb22222;
            /// @brief Jungle green rgb(41, 171, 135)
            inline constexpr u32 Jungle_green = 0x29ab87;
            /// @brief Violet (crayola) rgb(150, 61, 127)
            inline constexpr u32 Violet_crayola = 0x963d7f;
            /// @brief Plum rgb(142, 69, 133)
            inline constexpr u32 Plum = 0x8e4585;
            /// @brief Twilight lavender rgb(138, 73, 107)
            inline constexpr u32 Twilight_lavender = 0x8a496b;
            /// @brief Gold Fusion rgb(133, 117, 78)
            inline constexpr u32 Gold_Fusion = 0x85754e;
            /// @brief Dark turquoise rgb(0, 206, 209)
            inline constexpr u32 Dark_turquoise = 0x00ced1;
            /// @brief Spanish carmine rgb(209, 0, 71)
            inline constexpr u32 Spanish_carmine = 0xd10047;
            /// @brief Kelly green rgb(76, 187, 23)
            inline constexpr u32 Kelly_green = 0x4cbb17;
            /// @brief Light sea green rgb(32, 178, 170)
            inline constexpr u32 Light_sea_green = 0x20b2aa;
            /// @brief Amaranth purple rgb(171, 39, 79)
            inline constexpr u32 Amaranth_purple = 0xab274f;
            /// @brief Metallic red rgb(166, 44, 43)
            inline constexpr u32 Metallic_red = 0xa62c2b;
            /// @brief Purple Heart rgb(105, 53, 156)
            inline constexpr u32 Purple_Heart = 0x69359c;
            /// @brief Red rum rgb(151, 58, 74)
            inline constexpr u32 Red_rum = 0x973a4a;
            /// @brief May green rgb(76, 145, 65)
            inline constexpr u32 May_green = 0x4c9141;
            /// @brief French bistre rgb(133, 109, 77)
            inline constexpr u32 French_bistre = 0x856d4d;
            /// @brief Dim gray rgb(105, 105, 105)
            inline constexpr u32 Dim_gray = 0x696969;
            /// @brief True blue rgb(0, 115, 207)
            inline constexpr u32 True_blue = 0x0073cf;
            /// @brief Royal red rgb(208, 0, 96)
            inline constexpr u32 Royal_red = 0xd00060;
            /// @brief Neon gold rgb(207, 170, 1)
            inline constexpr u32 Neon_gold = 0xcfaa01;
            /// @brief Venetian red rgb(200, 8, 21)
            inline constexpr u32 Venetian_red = 0xc80815;
            /// @brief Brown (web) rgb(165, 42, 42)
            inline constexpr u32 Brown_web = 0xa52a2a;
            /// @brief Red-brown rgb(165, 42, 42)
            inline constexpr u32 Red_brown = 0xa52a2a;
            /// @brief Tawny rgb(205, 87, 0)
            inline constexpr u32 Tawny = 0xcd5700;
            /// @brief Mustard brown rgb(205, 122, 0)
            inline constexpr u32 Mustard_brown = 0xcd7a00;
            /// @brief Medium blue rgb(0, 0, 205)
            inline constexpr u32 Medium_blue = 0x0000cd;
            /// @brief Pictorial carmine rgb(195, 11, 78)
            inline constexpr u32 Pictorial_carmine = 0xc30b4e;
            /// @brief Upsdell red rgb(174, 32, 41)
            inline constexpr u32 Upsdell_red = 0xae2029;
            /// @brief Vine Green rgb(56, 163, 42)
            inline constexpr u32 Vine_Green = 0x38a32a;
            /// @brief Purple navy rgb(78, 81, 128)
            inline constexpr u32 Purple_navy = 0x4e5180;
            /// @brief Granite gray rgb(103, 103, 103)
            inline constexpr u32 Granite_gray = 0x676767;
            /// @brief Burnt orange rgb(204, 85, 0)
            inline constexpr u32 Burnt_orange = 0xcc5500;
            /// @brief Vivid amber rgb(204, 153, 0)
            inline constexpr u32 Vivid_amber = 0xcc9900;
            /// @brief Caribbean green rgb(0, 204, 153)
            inline constexpr u32 Caribbean_green = 0x00cc99;
            /// @brief Robin egg blue rgb(0, 204, 204)
            inline constexpr u32 Robin_egg_blue = 0x00cccc;
            /// @brief Vivid crimson rgb(204, 0, 51)
            inline constexpr u32 Vivid_crimson = 0xcc0033;
            /// @brief Limerick rgb(157, 194, 9)
            inline constexpr u32 Limerick = 0x9dc209;
            /// @brief Blue (pigment) rgb(51, 51, 153)
            inline constexpr u32 Blue_pigment = 0x333399;
            /// @brief Rebecca Purple rgb(102, 51, 153)
            inline constexpr u32 Rebecca_Purple = 0x663399;
            /// @brief Dark electric blue rgb(83, 104, 120)
            inline constexpr u32 Dark_electric_blue = 0x536878;
            /// @brief Payne's grey rgb(83, 104, 120)
            inline constexpr u32 Payne_s_grey = 0x536878;
            /// @brief Sapphire rgb(15, 82, 186)
            inline constexpr u32 Sapphire = 0x0f52ba;
            /// @brief Amaranth deep purple rgb(159, 43, 104)
            inline constexpr u32 Amaranth_deep_purple = 0x9f2b68;
            /// @brief Chestnut rgb(149, 69, 53)
            inline constexpr u32 Chestnut = 0x954535;
            /// @brief Blue-green rgb(13, 152, 186)
            inline constexpr u32 Blue_green = 0x0d98ba;
            /// @brief Green (Crayola) rgb(28, 172, 120)
            inline constexpr u32 Green_Crayola = 0x1cac78;
            /// @brief Chinese red rgb(170, 56, 30)
            inline constexpr u32 Chinese_red = 0xaa381e;
            /// @brief Citron rgb(159, 169, 31)
            inline constexpr u32 Citron = 0x9fa91f;
            /// @brief Quinacridone magenta rgb(142, 58, 89)
            inline constexpr u32 Quinacridone_magenta = 0x8e3a59;
            /// @brief Dark slate blue rgb(72, 61, 139)
            inline constexpr u32 Dark_slate_blue = 0x483d8b;
            /// @brief Cordovan rgb(137, 63, 69)
            inline constexpr u32 Cordovan = 0x893f45;
            /// @brief Purple (Munsell) rgb(159, 0, 197)
            inline constexpr u32 Purple_Munsell = 0x9f00c5;
            /// @brief Red (NCS) rgb(196, 2, 51)
            inline constexpr u32 Red_NCS = 0xc40233;
            /// @brief International orange (engineering) rgb(186, 22, 12)
            inline constexpr u32 International_orange_engineering = 0xba160c;
            /// @brief Rust rgb(183, 65, 14)
            inline constexpr u32 Rust = 0xb7410e;
            /// @brief Green-blue rgb(17, 100, 180)
            inline constexpr u32 Green_blue = 0x1164b4;
            /// @brief Japanese carmine rgb(157, 41, 51)
            inline constexpr u32 Japanese_carmine = 0x9d2933;
            /// @brief Raw umber rgb(130, 102, 68)
            inline constexpr u32 Raw_umber = 0x826644;
            /// @brief Cadet rgb(83, 104, 114)
            inline constexpr u32 Cadet = 0x536872;
            /// @brief Dark pastel green rgb(3, 192, 60)
            inline constexpr u32 Dark_pastel_green = 0x03c03c;
            /// @brief Dark goldenrod rgb(184, 134, 11)
            inline constexpr u32 Dark_goldenrod = 0xb8860b;
            /// @brief Wine red rgb(177, 18, 38)
            inline constexpr u32 Wine_red = 0xb11226;
            /// @brief Tuscan red rgb(124, 72, 72)
            inline constexpr u32 Tuscan_red = 0x7c4848;
            /// @brief Black coral rgb(84, 98, 111)
            inline constexpr u32 Black_coral = 0x54626f;
            /// @brief Big dip o’ruby rgb(156, 37, 66)
            inline constexpr u32 Big_dip_o_ruby = 0x9c2542;
            /// @brief Lapis lazuli rgb(38, 97, 156)
            inline constexpr u32 Lapis_lazuli = 0x26619c;
            /// @brief B'dazzled blue rgb(46, 88, 148)
            inline constexpr u32 B_dazzled_blue = 0x2e5894;
            /// @brief Illuminating emerald rgb(49, 145, 119)
            inline constexpr u32 Illuminating_emerald = 0x319177;
            /// @brief Solid pink rgb(137, 56, 67)
            inline constexpr u32 Solid_pink = 0x893843;
            /// @brief Viridian rgb(64, 130, 109)
            inline constexpr u32 Viridian = 0x40826d;
            /// @brief Hooker's green rgb(73, 121, 107)
            inline constexpr u32 Hooker_s_green = 0x49796b;
            /// @brief Mahogany rgb(192, 64, 0)
            inline constexpr u32 Mahogany = 0xc04000;
            /// @brief Violet (Caran d'Ache) rgb(110, 0, 192)
            inline constexpr u32 Violet_Caran_d_Ache = 0x6e00c0;
            /// @brief Metallic brown rgb(172, 67, 19)
            inline constexpr u32 Metallic_brown = 0xac4313;
            /// @brief Milk chocolate rgb(132, 86, 60)
            inline constexpr u32 Milk_chocolate = 0x84563c;
            /// @brief Lemon iced tea rgb(189, 48, 0)
            inline constexpr u32 Lemon_iced_tea = 0xbd3000;
            /// @brief Blue (NCS) rgb(0, 135, 189)
            inline constexpr u32 Blue_NCS = 0x0087bd;
            /// @brief Ocean boat blue rgb(0, 119, 190)
            inline constexpr u32 Ocean_boat_blue = 0x0077be;
            /// @brief Red-violet (Color wheel) rgb(146, 43, 62)
            inline constexpr u32 Red_violet_Color_wheel = 0x922b3e;
            /// @brief YInMn Blue rgb(46, 80, 144)
            inline constexpr u32 YInMn_Blue = 0x2e5090;
            /// @brief Maximum Green rgb(94, 140, 49)
            inline constexpr u32 Maximum_Green = 0x5e8c31;
            /// @brief Teal blue rgb(54, 117, 136)
            inline constexpr u32 Teal_blue = 0x367588;
            /// @brief Coyote brown rgb(129, 97, 60)
            inline constexpr u32 Coyote_brown = 0x81613c;
            /// @brief Cyber grape rgb(88, 66, 124)
            inline constexpr u32 Cyber_grape = 0x58427c;
            /// @brief French blue rgb(0, 114, 187)
            inline constexpr u32 French_blue = 0x0072bb;
            /// @brief Vivid burgundy rgb(159, 29, 53)
            inline constexpr u32 Vivid_burgundy = 0x9f1d35;
            /// @brief Old moss green rgb(134, 126, 54)
            inline constexpr u32 Old_moss_green = 0x867e36;
            /// @brief Fern green rgb(79, 121, 66)
            inline constexpr u32 Fern_green = 0x4f7942;
            /// @brief Absolute Zero rgb(0, 72, 186)
            inline constexpr u32 Absolute_Zero = 0x0048ba;
            /// @brief Tomato sauce rgb(178, 24, 7)
            inline constexpr u32 Tomato_sauce = 0xb21807;
            /// @brief Sea green rgb(46, 139, 87)
            inline constexpr u32 Sea_green = 0x2e8b57;
            /// @brief Independence rgb(76, 81, 109)
            inline constexpr u32 Independence = 0x4c516d;
            /// @brief Microsoft green rgb(125, 183, 0)
            inline constexpr u32 Microsoft_green = 0x7db700;
            /// @brief Star command blue rgb(0, 123, 184)
            inline constexpr u32 Star_command_blue = 0x007bb8;
            /// @brief Spanish blue rgb(0, 112, 184)
            inline constexpr u32 Spanish_blue = 0x0070b8;
            /// @brief Egyptian blue rgb(16, 52, 166)
            inline constexpr u32 Egyptian_blue = 0x1034a6;
            /// @brief Royal red rgb(155, 28, 49)
            inline constexpr u32 Royal_red = 0x9b1c31;
            /// @brief Maximum violet rgb(137, 47, 119)
            inline constexpr u32 Maximum_violet = 0x892f77;
            /// @brief Deep Space Sparkle rgb(74, 100, 108)
            inline constexpr u32 Deep_Space_Sparkle = 0x4a646c;
            /// @brief Wenge rgb(100, 84, 82)
            inline constexpr u32 Wenge = 0x645452;
            /// @brief Philippine gold rgb(177, 115, 4)
            inline constexpr u32 Philippine_gold = 0xb17304;
            /// @brief Vivid auburn rgb(146, 39, 36)
            inline constexpr u32 Vivid_auburn = 0x922724;
            /// @brief Cosmic cobalt rgb(46, 45, 136)
            inline constexpr u32 Cosmic_cobalt = 0x2e2d88;
            /// @brief Amazon rgb(59, 122, 87)
            inline constexpr u32 Amazon = 0x3b7a57;
            /// @brief Medium red rgb(177, 3, 4)
            inline constexpr u32 Medium_red = 0xb10304;
            /// @brief Maximum Purple rgb(115, 51, 128)
            inline constexpr u32 Maximum_Purple = 0x733380;
            /// @brief Ming rgb(54, 116, 125)
            inline constexpr u32 Ming = 0x36747d;
            /// @brief Bole rgb(121, 68, 59)
            inline constexpr u32 Bole = 0x79443b;
            /// @brief Medium Tuscan red rgb(121, 68, 59)
            inline constexpr u32 Medium_Tuscan_red = 0x79443b;
            /// @brief Artichoke green rgb(75, 111, 68)
            inline constexpr u32 Artichoke_green = 0x4b6f44;
            /// @brief Light gold rgb(178, 151, 0)
            inline constexpr u32 Light_gold = 0xb29700;
            /// @brief Spartan Crimson rgb(158, 19, 22)
            inline constexpr u32 Spartan_Crimson = 0x9e1316;
            /// @brief Olive drab (#3) rgb(107, 142, 35)
            inline constexpr u32 Olive_drab_3 = 0x6b8e23;
            /// @brief Eminence rgb(108, 48, 130)
            inline constexpr u32 Eminence = 0x6c3082;
            /// @brief Spanish bistre rgb(128, 117, 50)
            inline constexpr u32 Spanish_bistre = 0x807532;
            /// @brief Roast coffee rgb(112, 66, 65)
            inline constexpr u32 Roast_coffee = 0x704241;
            /// @brief Blue (Munsell) rgb(0, 147, 175)
            inline constexpr u32 Blue_Munsell = 0x0093af;
            /// @brief Honolulu blue rgb(0, 109, 176)
            inline constexpr u32 Honolulu_blue = 0x006db0;
            /// @brief Crimson (UA) rgb(175, 0, 42)
            inline constexpr u32 Crimson_UA = 0xaf002a;
            /// @brief Violet (RYB) rgb(134, 1, 175)
            inline constexpr u32 Violet_RYB = 0x8601af;
            /// @brief Rufous rgb(168, 28, 7)
            inline constexpr u32 Rufous = 0xa81c07;
            /// @brief Jazzberry jam rgb(165, 11, 94)
            inline constexpr u32 Jazzberry_jam = 0xa50b5e;
            /// @brief Samsung blue rgb(18, 39, 158)
            inline constexpr u32 Samsung_blue = 0x12279e;
            /// @brief KSU Purple rgb(81, 40, 136)
            inline constexpr u32 KSU_Purple = 0x512888;
            /// @brief Quincy rgb(106, 84, 69)
            inline constexpr u32 Quincy = 0x6a5445;
            /// @brief Mordant red 19 rgb(174, 12, 0)
            inline constexpr u32 Mordant_red_19 = 0xae0c00;
            /// @brief Green (Pantone) rgb(0, 173, 67)
            inline constexpr u32 Green_Pantone = 0x00ad43;
            /// @brief Blue Ribbon rgb(11, 16, 162)
            inline constexpr u32 Blue_Ribbon = 0x0b10a2;
            /// @brief Neon green rgb(19, 155, 66)
            inline constexpr u32 Neon_green = 0x139b42;
            /// @brief Golden brown rgb(153, 101, 21)
            inline constexpr u32 Golden_brown = 0x996515;
            /// @brief Bistre brown rgb(150, 113, 23)
            inline constexpr u32 Bistre_brown = 0x967117;
            /// @brief Mode beige rgb(150, 113, 23)
            inline constexpr u32 Mode_beige = 0x967117;
            /// @brief Sand dune rgb(150, 113, 23)
            inline constexpr u32 Sand_dune = 0x967117;
            /// @brief Sandy taupe rgb(150, 113, 23)
            inline constexpr u32 Sandy_taupe = 0x967117;
            /// @brief Slimy green rgb(41, 150, 23)
            inline constexpr u32 Slimy_green = 0x299617;
            /// @brief Forest green (web) rgb(34, 139, 34)
            inline constexpr u32 Forest_green_web = 0x228b22;
            /// @brief Burnt umber rgb(138, 51, 36)
            inline constexpr u32 Burnt_umber = 0x8a3324;
            /// @brief Dark raspberry rgb(135, 38, 87)
            inline constexpr u32 Dark_raspberry = 0x872657;
            /// @brief Metallic blue rgb(50, 82, 123)
            inline constexpr u32 Metallic_blue = 0x32527b;
            /// @brief Mud rgb(112, 84, 62)
            inline constexpr u32 Mud = 0x70543e;
            /// @brief Liver rgb(103, 76, 71)
            inline constexpr u32 Liver = 0x674c47;
            /// @brief Medium taupe rgb(103, 76, 71)
            inline constexpr u32 Medium_taupe = 0x674c47;
            /// @brief Ebony rgb(85, 93, 80)
            inline constexpr u32 Ebony = 0x555d50;
            /// @brief GO green rgb(0, 171, 102)
            inline constexpr u32 GO_green = 0x00ab66;
            /// @brief Cobalt blue rgb(0, 71, 171)
            inline constexpr u32 Cobalt_blue = 0x0047ab;
            /// @brief Windsor tan rgb(167, 85, 2)
            inline constexpr u32 Windsor_tan = 0xa75502;
            /// @brief Dark Fuchsia rgb(160, 9, 85)
            inline constexpr u32 Dark_Fuchsia = 0xa00955;
            /// @brief Spanish violet rgb(76, 40, 130)
            inline constexpr u32 Spanish_violet = 0x4c2882;
            /// @brief Myrtle green rgb(49, 120, 115)
            inline constexpr u32 Myrtle_green = 0x317873;
            /// @brief Umber rgb(99, 81, 71)
            inline constexpr u32 Umber = 0x635147;
            /// @brief Feldgrau rgb(77, 93, 83)
            inline constexpr u32 Feldgrau = 0x4d5d53;
            /// @brief Davy's grey rgb(85, 85, 85)
            inline constexpr u32 Davy_s_grey = 0x555555;
            /// @brief Jade rgb(0, 168, 107)
            inline constexpr u32 Jade = 0x00a86b;
            /// @brief Green (Munsell) rgb(0, 168, 119)
            inline constexpr u32 Green_Munsell = 0x00a877;
            /// @brief Cerulean rgb(0, 123, 167)
            inline constexpr u32 Cerulean = 0x007ba7;
            /// @brief Philippine blue rgb(0, 56, 167)
            inline constexpr u32 Philippine_blue = 0x0038a7;
            /// @brief Royal azure rgb(0, 56, 168)
            inline constexpr u32 Royal_azure = 0x0038a8;
            /// @brief Blue (Pantone) rgb(0, 24, 168)
            inline constexpr u32 Blue_Pantone = 0x0018a8;
            /// @brief Zaffre rgb(0, 20, 168)
            inline constexpr u32 Zaffre = 0x0014a8;
            /// @brief Sap green rgb(80, 125, 42)
            inline constexpr u32 Sap_green = 0x507d2a;
            /// @brief Garnet rgb(115, 54, 53)
            inline constexpr u32 Garnet = 0x733635;
            /// @brief Gold rgb(165, 124, 0)
            inline constexpr u32 Gold = 0xa57c00;
            /// @brief Green (pigment) rgb(0, 165, 80)
            inline constexpr u32 Green_pigment = 0x00a550;
            /// @brief Persian green rgb(0, 166, 147)
            inline constexpr u32 Persian_green = 0x00a693;
            /// @brief Medium Persian blue rgb(0, 103, 165)
            inline constexpr u32 Medium_Persian_blue = 0x0067a5;
            /// @brief Sapphire blue rgb(0, 103, 165)
            inline constexpr u32 Sapphire_blue = 0x0067a5;
            /// @brief Neon blue rgb(27, 3, 163)
            inline constexpr u32 Neon_blue = 0x1b03a3;
            /// @brief Fuzzy Wuzzy rgb(135, 66, 31)
            inline constexpr u32 Fuzzy_Wuzzy = 0x87421f;
            /// @brief Catawba rgb(112, 54, 66)
            inline constexpr u32 Catawba = 0x703642;
            /// @brief Coffee rgb(111, 78, 55)
            inline constexpr u32 Coffee = 0x6f4e37;
            /// @brief Tuscan brown rgb(111, 78, 55)
            inline constexpr u32 Tuscan_brown = 0x6f4e37;
            /// @brief Flirt rgb(162, 0, 109)
            inline constexpr u32 Flirt = 0xa2006d;
            /// @brief Puce red rgb(114, 47, 55)
            inline constexpr u32 Puce_red = 0x722f37;
            /// @brief Wine rgb(114, 47, 55)
            inline constexpr u32 Wine = 0x722f37;
            /// @brief Police blue rgb(55, 79, 107)
            inline constexpr u32 Police_blue = 0x374f6b;
            /// @brief Eggplant rgb(97, 64, 81)
            inline constexpr u32 Eggplant = 0x614051;
            /// @brief Green (NCS) rgb(0, 159, 107)
            inline constexpr u32 Green_NCS = 0x009f6b;
            /// @brief Kobe rgb(136, 45, 23)
            inline constexpr u32 Kobe = 0x882d17;
            /// @brief Sienna rgb(136, 45, 23)
            inline constexpr u32 Sienna = 0x882d17;
            /// @brief Antique ruby rgb(132, 27, 45)
            inline constexpr u32 Antique_ruby = 0x841b2d;
            /// @brief Shamrock green rgb(0, 158, 96)
            inline constexpr u32 Shamrock_green = 0x009e60;
            /// @brief Saddle Brown rgb(139, 69, 19)
            inline constexpr u32 Saddle_Brown = 0x8b4513;
            /// @brief St. Patrick's blue rgb(35, 41, 122)
            inline constexpr u32 St_Patrick_s_blue = 0x23297a;
            /// @brief Mustard green rgb(110, 110, 48)
            inline constexpr u32 Mustard_green = 0x6e6e30;
            /// @brief Dark liver rgb(83, 75, 79)
            inline constexpr u32 Dark_liver = 0x534b4f;
            /// @brief Paolo Veronese green rgb(0, 155, 125)
            inline constexpr u32 Paolo_Veronese_green = 0x009b7d;
            /// @brief Duke blue rgb(0, 0, 156)
            inline constexpr u32 Duke_blue = 0x00009c;
            /// @brief Metallic violet rgb(91, 10, 145)
            inline constexpr u32 Metallic_violet = 0x5b0a91;
            /// @brief Russet rgb(128, 70, 27)
            inline constexpr u32 Russet = 0x80461b;
            /// @brief OU Crimson red rgb(153, 0, 0)
            inline constexpr u32 OU_Crimson_red = 0x990000;
            /// @brief Green-cyan rgb(0, 153, 102)
            inline constexpr u32 Green_cyan = 0x009966;
            /// @brief Smalt (Dark powder blue) rgb(0, 51, 153)
            inline constexpr u32 Smalt_Dark_powder_blue = 0x003399;
            /// @brief Medium electric blue rgb(3, 80, 150)
            inline constexpr u32 Medium_electric_blue = 0x035096;
            /// @brief Byzantium rgb(112, 41, 99)
            inline constexpr u32 Byzantium = 0x702963;
            /// @brief Dark olive green rgb(85, 107, 47)
            inline constexpr u32 Dark_olive_green = 0x556b2f;
            /// @brief Quartz rgb(81, 72, 79)
            inline constexpr u32 Quartz = 0x51484f;
            /// @brief Brown rgb(150, 75, 0)
            inline constexpr u32 Brown = 0x964b00;
            /// @brief Viridian green rgb(0, 150, 152)
            inline constexpr u32 Viridian_green = 0x009698;
            /// @brief Carmine rgb(150, 0, 24)
            inline constexpr u32 Carmine = 0x960018;
            /// @brief Metallic Seaweed rgb(10, 126, 140)
            inline constexpr u32 Metallic_Seaweed = 0x0a7e8c;
            /// @brief Claret rgb(127, 23, 52)
            inline constexpr u32 Claret = 0x7f1734;
            /// @brief Falu red rgb(128, 24, 24)
            inline constexpr u32 Falu_red = 0x801818;
            /// @brief Midnight rgb(112, 38, 112)
            inline constexpr u32 Midnight = 0x702670;
            /// @brief Old mauve rgb(103, 49, 71)
            inline constexpr u32 Old_mauve = 0x673147;
            /// @brief Medium violet rgb(101, 49, 95)
            inline constexpr u32 Medium_violet = 0x65315f;
            /// @brief Dark byzantium rgb(93, 57, 84)
            inline constexpr u32 Dark_byzantium = 0x5d3954;
            /// @brief English violet rgb(86, 60, 92)
            inline constexpr u32 English_violet = 0x563c5c;
            /// @brief Old heliotrope rgb(86, 60, 92)
            inline constexpr u32 Old_heliotrope = 0x563c5c;
            /// @brief Sea blue rgb(0, 105, 148)
            inline constexpr u32 Sea_blue = 0x006994;
            /// @brief Hunter green rgb(53, 94, 59)
            inline constexpr u32 Hunter_green = 0x355e3b;
            /// @brief Spanish green rgb(0, 145, 80)
            inline constexpr u32 Spanish_green = 0x009150;
            /// @brief Blue sapphire rgb(18, 97, 128)
            inline constexpr u32 Blue_sapphire = 0x126180;
            /// @brief Salem rgb(23, 123, 77)
            inline constexpr u32 Salem = 0x177b4d;
            /// @brief India green rgb(19, 136, 8)
            inline constexpr u32 India_green = 0x138808;
            /// @brief Smokey Topaz rgb(131, 42, 13)
            inline constexpr u32 Smokey_Topaz = 0x832a0d;
            /// @brief Pansy purple rgb(120, 24, 74)
            inline constexpr u32 Pansy_purple = 0x78184a;
            /// @brief Palatinate purple rgb(104, 40, 96)
            inline constexpr u32 Palatinate_purple = 0x682860;
            /// @brief Mughal green rgb(48, 96, 48)
            inline constexpr u32 Mughal_green = 0x306030;
            /// @brief Purple taupe rgb(80, 64, 77)
            inline constexpr u32 Purple_taupe = 0x50404d;
            /// @brief Kobicha rgb(107, 68, 35)
            inline constexpr u32 Kobicha = 0x6b4423;
            /// @brief Van Dyke brown rgb(102, 66, 40)
            inline constexpr u32 Van_Dyke_brown = 0x664228;
            /// @brief Japanese violet rgb(91, 50, 86)
            inline constexpr u32 Japanese_violet = 0x5b3256;
            /// @brief Outer Space rgb(65, 74, 76)
            inline constexpr u32 Outer_Space = 0x414a4c;
            /// @brief Dark red rgb(139, 0, 0)
            inline constexpr u32 Dark_red = 0x8b0000;
            /// @brief Dark cyan rgb(0, 139, 139)
            inline constexpr u32 Dark_cyan = 0x008b8b;
            /// @brief Midnight blue rgb(0, 70, 140)
            inline constexpr u32 Midnight_blue = 0x00468c;
            /// @brief Dark blue rgb(0, 0, 139)
            inline constexpr u32 Dark_blue = 0x00008b;
            /// @brief Dark magenta rgb(139, 0, 139)
            inline constexpr u32 Dark_magenta = 0x8b008b;
            /// @brief UP maroon rgb(123, 17, 19)
            inline constexpr u32 UP_maroon = 0x7b1113;
            /// @brief Persian indigo rgb(50, 18, 122)
            inline constexpr u32 Persian_indigo = 0x32127a;
            /// @brief Persian plum rgb(112, 28, 28)
            inline constexpr u32 Persian_plum = 0x701c1c;
            /// @brief Prune rgb(112, 28, 28)
            inline constexpr u32 Prune = 0x701c1c;
            /// @brief Liver (organ) rgb(108, 46, 31)
            inline constexpr u32 Liver_organ = 0x6c2e1f;
            /// @brief Phthalo blue rgb(0, 15, 137)
            inline constexpr u32 Phthalo_blue = 0x000f89;
            /// @brief Dark spring green rgb(23, 114, 69)
            inline constexpr u32 Dark_spring_green = 0x177245;
            /// @brief Midnight blue rgb(25, 25, 112)
            inline constexpr u32 Midnight_blue = 0x191970;
            /// @brief Field drab rgb(108, 84, 30)
            inline constexpr u32 Field_drab = 0x6c541e;
            /// @brief Resolution blue rgb(0, 35, 135)
            inline constexpr u32 Resolution_blue = 0x002387;
            /// @brief Mardi Gras rgb(136, 0, 133)
            inline constexpr u32 Mardi_Gras = 0x880085;
            /// @brief Royal brown rgb(82, 59, 53)
            inline constexpr u32 Royal_brown = 0x523b35;
            /// @brief Philippine green rgb(0, 133, 67)
            inline constexpr u32 Philippine_green = 0x008543;
            /// @brief Dark brown rgb(101, 67, 33)
            inline constexpr u32 Dark_brown = 0x654321;
            /// @brief Otter brown rgb(101, 67, 33)
            inline constexpr u32 Otter_brown = 0x654321;
            /// @brief Charcoal rgb(54, 69, 79)
            inline constexpr u32 Charcoal = 0x36454f;
            /// @brief Neon dark green rgb(0, 132, 67)
            inline constexpr u32 Neon_dark_green = 0x008443;
            /// @brief Sepia rgb(112, 66, 20)
            inline constexpr u32 Sepia = 0x704214;
            /// @brief Antique bronze rgb(102, 93, 30)
            inline constexpr u32 Antique_bronze = 0x665d1e;
            /// @brief Rifle green rgb(68, 76, 56)
            inline constexpr u32 Rifle_green = 0x444c38;
            /// @brief Teal green rgb(0, 130, 127)
            inline constexpr u32 Teal_green = 0x00827f;
            /// @brief Indigo rgb(75, 0, 130)
            inline constexpr u32 Indigo = 0x4b0082;
            /// @brief Philippine violet rgb(129, 0, 127)
            inline constexpr u32 Philippine_violet = 0x81007f;
            /// @brief Maroon (HTML/CSS) rgb(128, 0, 0)
            inline constexpr u32 Maroon_HTML_CSS = 0x800000;
            /// @brief Olive rgb(128, 128, 0)
            inline constexpr u32 Olive = 0x808000;
            /// @brief Napier green rgb(42, 128, 0)
            inline constexpr u32 Napier_green = 0x2a8000;
            /// @brief Green (HTML/CSS color) rgb(0, 128, 0)
            inline constexpr u32 Green_HTML_CSS_color = 0x008000;
            /// @brief Office green rgb(0, 128, 0)
            inline constexpr u32 Office_green = 0x008000;
            /// @brief Spanish viridian rgb(0, 127, 92)
            inline constexpr u32 Spanish_viridian = 0x007f5c;
            /// @brief Generic viridian rgb(0, 127, 102)
            inline constexpr u32 Generic_viridian = 0x007f66;
            /// @brief Teal rgb(0, 128, 128)
            inline constexpr u32 Teal = 0x008080;
            /// @brief Navy blue rgb(0, 0, 128)
            inline constexpr u32 Navy_blue = 0x000080;
            /// @brief Patriarch rgb(128, 0, 128)
            inline constexpr u32 Patriarch = 0x800080;
            /// @brief Purple (HTML) rgb(128, 0, 128)
            inline constexpr u32 Purple_HTML = 0x800080;
            /// @brief Burgundy rgb(128, 0, 32)
            inline constexpr u32 Burgundy = 0x800020;
            /// @brief Oxblood rgb(128, 0, 32)
            inline constexpr u32 Oxblood = 0x800020;
            /// @brief La Salle green rgb(8, 120, 48)
            inline constexpr u32 La_Salle_green = 0x087830;
            /// @brief Dark moss green rgb(74, 93, 35)
            inline constexpr u32 Dark_moss_green = 0x4a5d23;
            /// @brief Barn red rgb(124, 10, 2)
            inline constexpr u32 Barn_red = 0x7c0a02;
            /// @brief Dark slate gray rgb(47, 79, 79)
            inline constexpr u32 Dark_slate_gray = 0x2f4f4f;
            /// @brief Chocolate (traditional) rgb(123, 63, 0)
            inline constexpr u32 Chocolate_traditional = 0x7b3f00;
            /// @brief Medium green rgb(3, 121, 73)
            inline constexpr u32 Medium_green = 0x037949;
            /// @brief Pullman Brown (UPS Brown) rgb(100, 65, 23)
            inline constexpr u32 Pullman_Brown_UPS_Brown = 0x644117;
            /// @brief Pine green rgb(1, 121, 111)
            inline constexpr u32 Pine_green = 0x01796f;
            /// @brief Dark lava rgb(72, 60, 50)
            inline constexpr u32 Dark_lava = 0x483c32;
            /// @brief Taupe rgb(72, 60, 50)
            inline constexpr u32 Taupe = 0x483c32;
            /// @brief Tropical rain forest rgb(0, 117, 94)
            inline constexpr u32 Tropical_rain_forest = 0x00755e;
            /// @brief Philippine bronze rgb(110, 58, 7)
            inline constexpr u32 Philippine_bronze = 0x6e3a07;
            /// @brief Skobeloff rgb(0, 116, 116)
            inline constexpr u32 Skobeloff = 0x007474;
            /// @brief Philippine brown rgb(93, 25, 22)
            inline constexpr u32 Philippine_brown = 0x5d1916;
            /// @brief Light chocolate cosmos rgb(85, 31, 47)
            inline constexpr u32 Light_chocolate_cosmos = 0x551f2f;
            /// @brief Old burgundy rgb(67, 48, 46)
            inline constexpr u32 Old_burgundy = 0x43302e;
            /// @brief Kombu green rgb(53, 66, 48)
            inline constexpr u32 Kombu_green = 0x354230;
            /// @brief Black olive rgb(59, 60, 54)
            inline constexpr u32 Black_olive = 0x3b3c36;
            /// @brief Dartmouth green rgb(0, 112, 60)
            inline constexpr u32 Dartmouth_green = 0x00703c;
            /// @brief Metallic green rgb(41, 110, 1)
            inline constexpr u32 Metallic_green = 0x296e01;
            /// @brief Space cadet rgb(29, 41, 81)
            inline constexpr u32 Space_cadet = 0x1d2951;
            /// @brief Onyx rgb(53, 56, 57)
            inline constexpr u32 Onyx = 0x353839;
            /// @brief Cadmium green rgb(0, 107, 60)
            inline constexpr u32 Cadmium_green = 0x006b3c;
            /// @brief Café Noir rgb(75, 54, 33)
            inline constexpr u32 Café_Noir = 0x4b3621;
            /// @brief Indigo dye rgb(0, 65, 106)
            inline constexpr u32 Indigo_dye = 0x00416a;
            /// @brief Philippine indigo rgb(0, 65, 106)
            inline constexpr u32 Philippine_indigo = 0x00416a;
            /// @brief Violin Brown rgb(103, 68, 3)
            inline constexpr u32 Violin_Brown = 0x674403;
            /// @brief Spanish purple rgb(102, 3, 60)
            inline constexpr u32 Spanish_purple = 0x66033c;
            /// @brief Royal green rgb(19, 98, 7)
            inline constexpr u32 Royal_green = 0x136207;
            /// @brief Tyrian purple rgb(102, 2, 60)
            inline constexpr u32 Tyrian_purple = 0x66023c;
            /// @brief Outer space (Crayola) rgb(45, 56, 58)
            inline constexpr u32 Outer_space_Crayola = 0x2d383a;
            /// @brief Jet rgb(52, 52, 52)
            inline constexpr u32 Jet = 0x343434;
            /// @brief Blood red rgb(102, 0, 0)
            inline constexpr u32 Blood_red = 0x660000;
            /// @brief Pakistan green rgb(0, 102, 0)
            inline constexpr u32 Pakistan_green = 0x006600;
            /// @brief Dark midnight blue rgb(0, 51, 102)
            inline constexpr u32 Dark_midnight_blue = 0x003366;
            /// @brief Royal blue rgb(0, 35, 102)
            inline constexpr u32 Royal_blue = 0x002366;
            /// @brief Dark green (X11) rgb(0, 100, 0)
            inline constexpr u32 Dark_green_X11 = 0x006400;
            /// @brief Seal brown rgb(89, 38, 11)
            inline constexpr u32 Seal_brown = 0x59260b;
            /// @brief Pineapple rgb(86, 60, 13)
            inline constexpr u32 Pineapple = 0x563c0d;
            /// @brief Russian violet rgb(50, 23, 77)
            inline constexpr u32 Russian_violet = 0x32174d;
            /// @brief Gunmetal rgb(42, 52, 57)
            inline constexpr u32 Gunmetal = 0x2a3439;
            /// @brief Lincoln green rgb(25, 89, 5)
            inline constexpr u32 Lincoln_green = 0x195905;
            /// @brief MSU green rgb(24, 69, 59)
            inline constexpr u32 MSU_green = 0x18453b;
            /// @brief Temptress rgb(60, 33, 38)
            inline constexpr u32 Temptress = 0x3c2126;
            /// @brief Bistre rgb(61, 43, 31)
            inline constexpr u32 Bistre = 0x3d2b1f;
            /// @brief Olive drab #7 rgb(60, 52, 31)
            inline constexpr u32 Olive_drab_7 = 0x3c341f;
            /// @brief Midnight green (Eagle green) rgb(0, 73, 83)
            inline constexpr u32 Midnight_green_Eagle_green = 0x004953;
            /// @brief Prussian blue rgb(0, 49, 83)
            inline constexpr u32 Prussian_blue = 0x003153;
            /// @brief Medium jungle green rgb(28, 53, 45)
            inline constexpr u32 Medium_jungle_green = 0x1c352d;
            /// @brief Pine green rgb(42, 47, 35)
            inline constexpr u32 Pine_green = 0x2a2f23;
            /// @brief Dark sienna rgb(60, 20, 20)
            inline constexpr u32 Dark_sienna = 0x3c1414;
            /// @brief Dark purple rgb(48, 25, 52)
            inline constexpr u32 Dark_purple = 0x301934;
            /// @brief Charleston green rgb(35, 43, 43)
            inline constexpr u32 Charleston_green = 0x232b2b;
            /// @brief Deep jungle green rgb(0, 75, 73)
            inline constexpr u32 Deep_jungle_green = 0x004b49;
            /// @brief Oxford blue rgb(0, 33, 71)
            inline constexpr u32 Oxford_blue = 0x002147;
            /// @brief Phthalo green rgb(18, 53, 36)
            inline constexpr u32 Phthalo_green = 0x123524;
            /// @brief Forest green (traditional) rgb(1, 68, 33)
            inline constexpr u32 Forest_green_traditional = 0x014421;
            /// @brief Raisin black rgb(36, 33, 36)
            inline constexpr u32 Raisin_black = 0x242124;
            /// @brief British racing green rgb(0, 66, 37)
            inline constexpr u32 British_racing_green = 0x004225;
            /// @brief Black bean rgb(61, 12, 2)
            inline constexpr u32 Black_bean = 0x3d0c02;
            /// @brief Maastricht Blue rgb(0, 28, 61)
            inline constexpr u32 Maastricht_Blue = 0x001c3d;
            /// @brief Sacramento State green rgb(4, 57, 39)
            inline constexpr u32 Sacramento_State_green = 0x043927;
            /// @brief Dark jungle green rgb(26, 36, 33)
            inline constexpr u32 Dark_jungle_green = 0x1a2421;
            /// @brief Eerie black rgb(27, 27, 27)
            inline constexpr u32 Eerie_black = 0x1b1b1b;
            /// @brief Dark green rgb(1, 50, 32)
            inline constexpr u32 Dark_green = 0x013220;
            /// @brief Zinnwaldite rgb(44, 22, 8)
            inline constexpr u32 Zinnwaldite = 0x2c1608;
            /// @brief Root beer rgb(41, 14, 5)
            inline constexpr u32 Root_beer = 0x290e05;
            /// @brief Licorice rgb(26, 17, 16)
            inline constexpr u32 Licorice = 0x1a1110;
            /// @brief Smoky black rgb(16, 12, 8)
            inline constexpr u32 Smoky_black = 0x100c08;
            /// @brief Vampire Black rgb(8, 8, 8)
            inline constexpr u32 Vampire_Black = 0x080808;
            /// @brief Black rgb(0, 0, 0)
            inline constexpr u32 Black = 0x000000;
            /// @brief Registration black rgb(0, 0, 0)
            inline constexpr u32 Registration_black = 0x000000;
        } // namespace Color
    } // namespace Graphics
} // namespace Sola

#endif
