#ifndef GRAPHICS_COLOR_HPP
#define GRAPHICS_COLOR_HPP

#include "SolaCommon.hpp"

namespace Sola::Graphics {
    /// @brief This namespace contains most of named color variables and some other color related stuff.
    ///
    /// Color list written in this namespace was copied from the list of colors in
    /// [XKCD color name survey](https://xkcd.com/color/rgb/). Real big thanks to them for making and
    /// publishing this list.
    namespace Color {
        /// @brief White rgb(255, 255, 255)
        inline constexpr u32 White = 0xffffff;
        /// @brief Pale Grey rgb(253, 253, 254)
        inline constexpr u32 PaleGrey = 0xfdfdfe;
        /// @brief Very Light Pink rgb(255, 244, 242)
        inline constexpr u32 VeryLightPink = 0xfff4f2;
        /// @brief Off White rgb(255, 255, 228)
        inline constexpr u32 OffWhite = 0xffffe4;
        /// @brief Ice Blue rgb(215, 255, 254)
        inline constexpr u32 IceBlue = 0xd7fffe;
        /// @brief Ice rgb(214, 255, 250)
        inline constexpr u32 Ice = 0xd6fffa;
        /// @brief Very Pale Blue rgb(214, 255, 254)
        inline constexpr u32 VeryPaleBlue = 0xd6fffe;
        /// @brief Very Light Blue rgb(213, 255, 255)
        inline constexpr u32 VeryLightBlue = 0xd5ffff;
        /// @brief Eggshell rgb(255, 255, 212)
        inline constexpr u32 Eggshell = 0xffffd4;
        /// @brief Really Light Blue rgb(212, 255, 255)
        inline constexpr u32 ReallyLightBlue = 0xd4ffff;
        /// @brief Pale rgb(255, 249, 208)
        inline constexpr u32 Pale = 0xfff9d0;
        /// @brief Light Pink rgb(255, 209, 223)
        inline constexpr u32 LightPink = 0xffd1df;
        /// @brief Pale Pink rgb(255, 207, 220)
        inline constexpr u32 PalePink = 0xffcfdc;
        /// @brief Pale Blue rgb(208, 254, 254)
        inline constexpr u32 PaleBlue = 0xd0fefe;
        /// @brief Pale Lavender rgb(238, 207, 254)
        inline constexpr u32 PaleLavender = 0xeecffe;
        /// @brief Pale Mauve rgb(254, 208, 252)
        inline constexpr u32 PaleMauve = 0xfed0fc;
        /// @brief Very Light Purple rgb(246, 206, 252)
        inline constexpr u32 VeryLightPurple = 0xf6cefc;
        /// @brief Ivory rgb(255, 255, 203)
        inline constexpr u32 Ivory = 0xffffcb;
        /// @brief Ecru rgb(254, 255, 202)
        inline constexpr u32 Ecru = 0xfeffca;
        /// @brief Light Light Blue rgb(202, 255, 251)
        inline constexpr u32 LightLightBlue = 0xcafffb;
        /// @brief Pale Lilac rgb(228, 203, 255)
        inline constexpr u32 PaleLilac = 0xe4cbff;
        /// @brief Light Lilac rgb(237, 200, 255)
        inline constexpr u32 LightLilac = 0xedc8ff;
        /// @brief Light Sky Blue rgb(198, 252, 255)
        inline constexpr u32 LightSkyBlue = 0xc6fcff;
        /// @brief Egg Shell rgb(255, 252, 196)
        inline constexpr u32 EggShell = 0xfffcc4;
        /// @brief Eggshell Blue rgb(196, 255, 247)
        inline constexpr u32 EggshellBlue = 0xc4fff7;
        /// @brief Light Rose rgb(255, 197, 203)
        inline constexpr u32 LightRose = 0xffc5cb;
        /// @brief Light Lavender rgb(223, 197, 254)
        inline constexpr u32 LightLavender = 0xdfc5fe;
        /// @brief Cream rgb(255, 255, 194)
        inline constexpr u32 Cream = 0xffffc2;
        /// @brief Very Light Green rgb(209, 255, 189)
        inline constexpr u32 VeryLightGreen = 0xd1ffbd;
        /// @brief Light Lavendar rgb(239, 192, 254)
        inline constexpr u32 LightLavendar = 0xefc0fe;
        /// @brief Pale Rose rgb(253, 193, 197)
        inline constexpr u32 PaleRose = 0xfdc1c5;
        /// @brief Light Periwinkle rgb(193, 198, 252)
        inline constexpr u32 LightPeriwinkle = 0xc1c6fc;
        /// @brief Duck Egg Blue rgb(195, 251, 244)
        inline constexpr u32 DuckEggBlue = 0xc3fbf4;
        /// @brief Pale Sky Blue rgb(189, 246, 254)
        inline constexpr u32 PaleSkyBlue = 0xbdf6fe;
        /// @brief Pastel Pink rgb(255, 186, 205)
        inline constexpr u32 PastelPink = 0xffbacd;
        /// @brief Very Pale Green rgb(207, 253, 188)
        inline constexpr u32 VeryPaleGreen = 0xcffdbc;
        /// @brief Pale Aqua rgb(184, 255, 235)
        inline constexpr u32 PaleAqua = 0xb8ffeb;
        /// @brief Pale Cyan rgb(183, 255, 250)
        inline constexpr u32 PaleCyan = 0xb7fffa;
        /// @brief Baby Pink rgb(255, 183, 206)
        inline constexpr u32 BabyPink = 0xffb7ce;
        /// @brief Light Beige rgb(255, 254, 182)
        inline constexpr u32 LightBeige = 0xfffeb6;
        /// @brief Creme rgb(255, 255, 182)
        inline constexpr u32 Creme = 0xffffb6;
        /// @brief Light Mint rgb(182, 255, 187)
        inline constexpr u32 LightMint = 0xb6ffbb;
        /// @brief Celadon rgb(190, 253, 183)
        inline constexpr u32 Celadon = 0xbefdb7;
        /// @brief Pale Green rgb(199, 253, 181)
        inline constexpr u32 PaleGreen = 0xc7fdb5;
        /// @brief Light Grey rgb(216, 220, 214)
        inline constexpr u32 LightGrey = 0xd8dcd6;
        /// @brief Powder Pink rgb(255, 178, 208)
        inline constexpr u32 PowderPink = 0xffb2d0;
        /// @brief Light Violet rgb(214, 180, 252)
        inline constexpr u32 LightViolet = 0xd6b4fc;
        /// @brief Light Peach rgb(255, 216, 177)
        inline constexpr u32 LightPeach = 0xffd8b1;
        /// @brief Light Light Green rgb(200, 255, 176)
        inline constexpr u32 LightLightGreen = 0xc8ffb0;
        /// @brief Pale Peach rgb(255, 229, 173)
        inline constexpr u32 PalePeach = 0xffe5ad;
        /// @brief Parchment rgb(254, 252, 175)
        inline constexpr u32 Parchment = 0xfefcaf;
        /// @brief Soft Pink rgb(253, 176, 192)
        inline constexpr u32 SoftPink = 0xfdb0c0;
        /// @brief Powder Blue rgb(177, 209, 252)
        inline constexpr u32 PowderBlue = 0xb1d1fc;
        /// @brief Light Cyan rgb(172, 255, 252)
        inline constexpr u32 LightCyan = 0xacfffc;
        /// @brief Light Tan rgb(251, 238, 172)
        inline constexpr u32 LightTan = 0xfbeeac;
        /// @brief Pale Violet rgb(206, 174, 250)
        inline constexpr u32 PaleViolet = 0xceaefa;
        /// @brief Light Seafoam Green rgb(167, 255, 181)
        inline constexpr u32 LightSeafoamGreen = 0xa7ffb5;
        /// @brief Light Mint Green rgb(166, 251, 178)
        inline constexpr u32 LightMintGreen = 0xa6fbb2;
        /// @brief Pastel Purple rgb(202, 160, 255)
        inline constexpr u32 PastelPurple = 0xcaa0ff;
        /// @brief Baby Blue rgb(162, 207, 254)
        inline constexpr u32 BabyBlue = 0xa2cffe;
        /// @brief Pastel Blue rgb(162, 191, 254)
        inline constexpr u32 PastelBlue = 0xa2bffe;
        /// @brief Lilac rgb(206, 162, 253)
        inline constexpr u32 Lilac = 0xcea2fd;
        /// @brief Light Pastel Green rgb(178, 251, 165)
        inline constexpr u32 LightPastelGreen = 0xb2fba5;
        /// @brief Pale Turquoise rgb(165, 251, 213)
        inline constexpr u32 PaleTurquoise = 0xa5fbd5;
        /// @brief Pastel Green rgb(176, 255, 157)
        inline constexpr u32 PastelGreen = 0xb0ff9d;
        /// @brief Buff rgb(254, 246, 158)
        inline constexpr u32 Buff = 0xfef69e;
        /// @brief Mint rgb(159, 254, 176)
        inline constexpr u32 Mint = 0x9ffeb0;
        /// @brief Light Seafoam rgb(160, 254, 191)
        inline constexpr u32 LightSeafoam = 0xa0febf;
        /// @brief Tea Green rgb(189, 248, 163)
        inline constexpr u32 TeaGreen = 0xbdf8a3;
        /// @brief Washed Out Green rgb(188, 245, 166)
        inline constexpr u32 WashedOutGreen = 0xbcf5a6;
        /// @brief Pale Salmon rgb(255, 177, 154)
        inline constexpr u32 PaleSalmon = 0xffb19a;
        /// @brief Dark Cream rgb(255, 243, 154)
        inline constexpr u32 DarkCream = 0xfff39a;
        /// @brief Light Sage rgb(188, 236, 172)
        inline constexpr u32 LightSage = 0xbcecac;
        /// @brief Light Blue Grey rgb(183, 201, 226)
        inline constexpr u32 LightBlueGrey = 0xb7c9e2;
        /// @brief Pale Light Green rgb(177, 252, 153)
        inline constexpr u32 PaleLightGreen = 0xb1fc99;
        /// @brief Celery rgb(193, 253, 149)
        inline constexpr u32 Celery = 0xc1fd95;
        /// @brief Light Khaki rgb(230, 242, 162)
        inline constexpr u32 LightKhaki = 0xe6f2a2;
        /// @brief Light Salmon rgb(254, 169, 147)
        inline constexpr u32 LightSalmon = 0xfea993;
        /// @brief Light Blue rgb(149, 208, 252)
        inline constexpr u32 LightBlue = 0x95d0fc;
        /// @brief Robins Egg Blue rgb(152, 239, 249)
        inline constexpr u32 RobinsEggBlue = 0x98eff9;
        /// @brief Baby Purple rgb(202, 155, 247)
        inline constexpr u32 BabyPurple = 0xca9bf7;
        /// @brief Mint Green rgb(143, 255, 159)
        inline constexpr u32 MintGreen = 0x8fff9f;
        /// @brief Foam Green rgb(144, 253, 169)
        inline constexpr u32 FoamGreen = 0x90fda9;
        /// @brief Light Sea Green rgb(152, 246, 176)
        inline constexpr u32 LightSeaGreen = 0x98f6b0;
        /// @brief Lavender rgb(199, 159, 239)
        inline constexpr u32 Lavender = 0xc79fef;
        /// @brief Beige rgb(230, 218, 166)
        inline constexpr u32 Beige = 0xe6daa6;
        /// @brief Silver rgb(197, 201, 199)
        inline constexpr u32 Silver = 0xc5c9c7;
        /// @brief Baby Green rgb(140, 255, 158)
        inline constexpr u32 BabyGreen = 0x8cff9e;
        /// @brief Light Aqua rgb(140, 255, 219)
        inline constexpr u32 LightAqua = 0x8cffdb;
        /// @brief Liliac rgb(196, 142, 253)
        inline constexpr u32 Liliac = 0xc48efd;
        /// @brief Peachy Pink rgb(255, 154, 138)
        inline constexpr u32 PeachyPink = 0xff9a8a;
        /// @brief Periwinkle Blue rgb(143, 153, 251)
        inline constexpr u32 PeriwinkleBlue = 0x8f99fb;
        /// @brief Light Yellowish Green rgb(194, 255, 137)
        inline constexpr u32 LightYellowishGreen = 0xc2ff89;
        /// @brief Robin Egg Blue rgb(138, 241, 254)
        inline constexpr u32 RobinEggBlue = 0x8af1fe;
        /// @brief Carolina Blue rgb(138, 184, 254)
        inline constexpr u32 CarolinaBlue = 0x8ab8fe;
        /// @brief Manilla rgb(255, 250, 134)
        inline constexpr u32 Manilla = 0xfffa86;
        /// @brief Pistachio rgb(192, 250, 139)
        inline constexpr u32 Pistachio = 0xc0fa8b;
        /// @brief Cloudy Blue rgb(172, 194, 217)
        inline constexpr u32 CloudyBlue = 0xacc2d9;
        /// @brief Pale Yellow rgb(255, 255, 132)
        inline constexpr u32 PaleYellow = 0xffff84;
        /// @brief Rosa rgb(254, 134, 164)
        inline constexpr u32 Rosa = 0xfe86a4;
        /// @brief Bubblegum Pink rgb(254, 131, 204)
        inline constexpr u32 BubblegumPink = 0xfe83cc;
        /// @brief Pinky rgb(252, 134, 170)
        inline constexpr u32 Pinky = 0xfc86aa;
        /// @brief Light Grey Green rgb(183, 225, 161)
        inline constexpr u32 LightGreyGreen = 0xb7e1a1;
        /// @brief Butter rgb(255, 255, 129)
        inline constexpr u32 Butter = 0xffff81;
        /// @brief Pink rgb(255, 129, 192)
        inline constexpr u32 Pink = 0xff81c0;
        /// @brief Light Pea Green rgb(196, 254, 130)
        inline constexpr u32 LightPeaGreen = 0xc4fe82;
        /// @brief Periwinkle rgb(142, 130, 254)
        inline constexpr u32 Periwinkle = 0x8e82fe;
        /// @brief Blush Pink rgb(254, 130, 140)
        inline constexpr u32 BlushPink = 0xfe828c;
        /// @brief Lavender Blue rgb(139, 136, 248)
        inline constexpr u32 LavenderBlue = 0x8b88f8;
        /// @brief Blush rgb(242, 158, 142)
        inline constexpr u32 Blush = 0xf29e8e;
        /// @brief Hospital Green rgb(155, 229, 170)
        inline constexpr u32 HospitalGreen = 0x9be5aa;
        /// @brief Faded Yellow rgb(254, 255, 127)
        inline constexpr u32 FadedYellow = 0xfeff7f;
        /// @brief Banana rgb(255, 255, 126)
        inline constexpr u32 Banana = 0xffff7e;
        /// @brief Carnation Pink rgb(255, 127, 167)
        inline constexpr u32 CarnationPink = 0xff7fa7;
        /// @brief Yellowish Tan rgb(252, 252, 129)
        inline constexpr u32 YellowishTan = 0xfcfc81;
        /// @brief Sky rgb(130, 202, 252)
        inline constexpr u32 Sky = 0x82cafc;
        /// @brief Rose Pink rgb(247, 135, 154)
        inline constexpr u32 RosePink = 0xf7879a;
        /// @brief Peach rgb(255, 176, 124)
        inline constexpr u32 Peach = 0xffb07c;
        /// @brief Light Yellow Green rgb(204, 253, 127)
        inline constexpr u32 LightYellowGreen = 0xccfd7f;
        /// @brief Easter Green rgb(140, 253, 126)
        inline constexpr u32 EasterGreen = 0x8cfd7e;
        /// @brief Faded Pink rgb(222, 157, 172)
        inline constexpr u32 FadedPink = 0xde9dac;
        /// @brief Light Yellow rgb(255, 254, 122)
        inline constexpr u32 LightYellow = 0xfffe7a;
        /// @brief Salmon Pink rgb(254, 123, 124)
        inline constexpr u32 SalmonPink = 0xfe7b7c;
        /// @brief Light Aquamarine rgb(123, 253, 199)
        inline constexpr u32 LightAquamarine = 0x7bfdc7;
        /// @brief Wheat rgb(251, 221, 126)
        inline constexpr u32 Wheat = 0xfbdd7e;
        /// @brief Light Blue Green rgb(126, 251, 179)
        inline constexpr u32 LightBlueGreen = 0x7efbb3;
        /// @brief Seafoam rgb(128, 249, 173)
        inline constexpr u32 Seafoam = 0x80f9ad;
        /// @brief Custard rgb(255, 253, 120)
        inline constexpr u32 Custard = 0xfffd78;
        /// @brief Carnation rgb(253, 121, 143)
        inline constexpr u32 Carnation = 0xfd798f;
        /// @brief Lightgreen rgb(118, 255, 123)
        inline constexpr u32 Lightgreen = 0x76ff7b;
        /// @brief Straw rgb(252, 246, 121)
        inline constexpr u32 Straw = 0xfcf679;
        /// @brief Pig Pink rgb(231, 142, 165)
        inline constexpr u32 PigPink = 0xe78ea5;
        /// @brief Light Teal rgb(144, 228, 193)
        inline constexpr u32 LightTeal = 0x90e4c1;
        /// @brief Butter Yellow rgb(255, 253, 116)
        inline constexpr u32 ButterYellow = 0xfffd74;
        /// @brief Light Bluish Green rgb(118, 253, 168)
        inline constexpr u32 LightBluishGreen = 0x76fda8;
        /// @brief Light Green rgb(150, 249, 123)
        inline constexpr u32 LightGreen = 0x96f97b;
        /// @brief Seafoam Green rgb(122, 249, 171)
        inline constexpr u32 SeafoamGreen = 0x7af9ab;
        /// @brief Light Turquoise rgb(126, 244, 204)
        inline constexpr u32 LightTurquoise = 0x7ef4cc;
        /// @brief Perrywinkle rgb(143, 140, 231)
        inline constexpr u32 Perrywinkle = 0x8f8ce7;
        /// @brief Sky Blue rgb(117, 187, 253)
        inline constexpr u32 SkyBlue = 0x75bbfd;
        /// @brief Lightblue rgb(123, 200, 246)
        inline constexpr u32 Lightblue = 0x7bc8f6;
        /// @brief Light Grey Blue rgb(157, 188, 212)
        inline constexpr u32 LightGreyBlue = 0x9dbcd4;
        /// @brief Pinkish Grey rgb(200, 172, 169)
        inline constexpr u32 PinkishGrey = 0xc8aca9;
        /// @brief Pastel Yellow rgb(255, 254, 113)
        inline constexpr u32 PastelYellow = 0xfffe71;
        /// @brief Easter Purple rgb(192, 113, 254)
        inline constexpr u32 EasterPurple = 0xc071fe;
        /// @brief Sandy Yellow rgb(253, 238, 115)
        inline constexpr u32 SandyYellow = 0xfdee73;
        /// @brief Pale Lime rgb(190, 253, 115)
        inline constexpr u32 PaleLime = 0xbefd73;
        /// @brief Yellow Tan rgb(255, 227, 110)
        inline constexpr u32 YellowTan = 0xffe36e;
        /// @brief Key Lime rgb(174, 255, 110)
        inline constexpr u32 KeyLime = 0xaeff6e;
        /// @brief Light Purple rgb(191, 119, 246)
        inline constexpr u32 LightPurple = 0xbf77f6;
        /// @brief Tiffany Blue rgb(123, 242, 218)
        inline constexpr u32 TiffanyBlue = 0x7bf2da;
        /// @brief Salmon rgb(255, 121, 108)
        inline constexpr u32 Salmon = 0xff796c;
        /// @brief Apricot rgb(255, 177, 109)
        inline constexpr u32 Apricot = 0xffb16d;
        /// @brief Bubblegum rgb(255, 108, 181)
        inline constexpr u32 Bubblegum = 0xff6cb5;
        /// @brief Robins Egg rgb(109, 237, 253)
        inline constexpr u32 RobinsEgg = 0x6dedfd;
        /// @brief Sandy rgb(241, 218, 122)
        inline constexpr u32 Sandy = 0xf1da7a;
        /// @brief Pale Gold rgb(253, 222, 108)
        inline constexpr u32 PaleGold = 0xfdde6c;
        /// @brief Light Lime rgb(174, 253, 108)
        inline constexpr u32 LightLime = 0xaefd6c;
        /// @brief Spring Green rgb(169, 249, 113)
        inline constexpr u32 SpringGreen = 0xa9f971;
        /// @brief Bubble Gum Pink rgb(255, 105, 175)
        inline constexpr u32 BubbleGumPink = 0xff69af;
        /// @brief Light Lime Green rgb(185, 255, 102)
        inline constexpr u32 LightLimeGreen = 0xb9ff66;
        /// @brief Light Urple rgb(179, 111, 246)
        inline constexpr u32 LightUrple = 0xb36ff6;
        /// @brief Purply Pink rgb(240, 117, 230)
        inline constexpr u32 PurplyPink = 0xf075e6;
        /// @brief Pale Lime Green rgb(177, 255, 101)
        inline constexpr u32 PaleLimeGreen = 0xb1ff65;
        /// @brief Pale Purple rgb(183, 144, 212)
        inline constexpr u32 PalePurple = 0xb790d4;
        /// @brief Canary rgb(253, 255, 99)
        inline constexpr u32 Canary = 0xfdff63;
        /// @brief Candy Pink rgb(255, 99, 233)
        inline constexpr u32 CandyPink = 0xff63e9;
        /// @brief Sand Yellow rgb(252, 225, 102)
        inline constexpr u32 SandYellow = 0xfce166;
        /// @brief Cornflower rgb(106, 121, 247)
        inline constexpr u32 Cornflower = 0x6a79f7;
        /// @brief Lavender Pink rgb(221, 133, 215)
        inline constexpr u32 LavenderPink = 0xdd85d7;
        /// @brief Bright Lavender rgb(199, 96, 255)
        inline constexpr u32 BrightLavender = 0xc760ff;
        /// @brief Coral Pink rgb(255, 97, 99)
        inline constexpr u32 CoralPink = 0xff6163;
        /// @brief Lighter Green rgb(117, 253, 99)
        inline constexpr u32 LighterGreen = 0x75fd63;
        /// @brief Yellowish rgb(250, 238, 102)
        inline constexpr u32 Yellowish = 0xfaee66;
        /// @brief Dusty Pink rgb(213, 138, 148)
        inline constexpr u32 DustyPink = 0xd58a94;
        /// @brief Rosy Pink rgb(246, 104, 142)
        inline constexpr u32 RosyPink = 0xf6688e;
        /// @brief Violet Pink rgb(251, 95, 252)
        inline constexpr u32 VioletPink = 0xfb5ffc;
        /// @brief Light Greenish Blue rgb(99, 247, 180)
        inline constexpr u32 LightGreenishBlue = 0x63f7b4;
        /// @brief Light Grass Green rgb(154, 247, 100)
        inline constexpr u32 LightGrassGreen = 0x9af764;
        /// @brief Pinkish Tan rgb(217, 155, 130)
        inline constexpr u32 PinkishTan = 0xd99b82;
        /// @brief Dull Pink rgb(213, 134, 157)
        inline constexpr u32 DullPink = 0xd5869d;
        /// @brief Light Gold rgb(253, 220, 92)
        inline constexpr u32 LightGold = 0xfddc5c;
        /// @brief Bright Lilac rgb(201, 94, 251)
        inline constexpr u32 BrightLilac = 0xc95efb;
        /// @brief Light Magenta rgb(250, 95, 247)
        inline constexpr u32 LightMagenta = 0xfa5ff7;
        /// @brief Sand rgb(226, 202, 118)
        inline constexpr u32 Sand = 0xe2ca76;
        /// @brief Pear rgb(203, 248, 95)
        inline constexpr u32 Pear = 0xcbf85f;
        /// @brief Light Mustard rgb(247, 213, 96)
        inline constexpr u32 LightMustard = 0xf7d560;
        /// @brief Pale Orange rgb(255, 167, 86)
        inline constexpr u32 PaleOrange = 0xffa756;
        /// @brief Very Light Brown rgb(211, 182, 131)
        inline constexpr u32 VeryLightBrown = 0xd3b683;
        /// @brief Greyish Pink rgb(200, 141, 148)
        inline constexpr u32 GreyishPink = 0xc88d94;
        /// @brief Melon rgb(255, 120, 85)
        inline constexpr u32 Melon = 0xff7855;
        /// @brief Grapefruit rgb(253, 89, 86)
        inline constexpr u32 Grapefruit = 0xfd5956;
        /// @brief Light Green Blue rgb(86, 252, 162)
        inline constexpr u32 LightGreenBlue = 0x56fca2;
        /// @brief Medium Pink rgb(243, 97, 150)
        inline constexpr u32 MediumPink = 0xf36196;
        /// @brief Grey Pink rgb(195, 144, 155)
        inline constexpr u32 GreyPink = 0xc3909b;
        /// @brief Light Mauve rgb(194, 146, 161)
        inline constexpr u32 LightMauve = 0xc292a1;
        /// @brief Orange Pink rgb(255, 111, 82)
        inline constexpr u32 OrangePink = 0xff6f52;
        /// @brief Lemon rgb(253, 255, 82)
        inline constexpr u32 Lemon = 0xfdff52;
        /// @brief Light Bright Green rgb(83, 254, 92)
        inline constexpr u32 LightBrightGreen = 0x53fe5c;
        /// @brief Sea Green rgb(83, 252, 161)
        inline constexpr u32 SeaGreen = 0x53fca1;
        /// @brief Warm Pink rgb(251, 85, 129)
        inline constexpr u32 WarmPink = 0xfb5581;
        /// @brief Pastel Orange rgb(255, 150, 79)
        inline constexpr u32 PastelOrange = 0xff964f;
        /// @brief Lighter Purple rgb(165, 90, 244)
        inline constexpr u32 LighterPurple = 0xa55af4;
        /// @brief Soft Blue rgb(100, 136, 234)
        inline constexpr u32 SoftBlue = 0x6488ea;
        /// @brief Pale Olive Green rgb(177, 210, 123)
        inline constexpr u32 PaleOliveGreen = 0xb1d27b;
        /// @brief Pale Olive rgb(185, 204, 129)
        inline constexpr u32 PaleOlive = 0xb9cc81;
        /// @brief Pale Teal rgb(130, 203, 178)
        inline constexpr u32 PaleTeal = 0x82cbb2;
        /// @brief Pinkish Orange rgb(255, 114, 76)
        inline constexpr u32 PinkishOrange = 0xff724c;
        /// @brief Light Neon Green rgb(78, 253, 84)
        inline constexpr u32 LightNeonGreen = 0x4efd54;
        /// @brief Coral rgb(252, 90, 80)
        inline constexpr u32 Coral = 0xfc5a50;
        /// @brief Fawn rgb(207, 175, 123)
        inline constexpr u32 Fawn = 0xcfaf7b;
        /// @brief Banana Yellow rgb(250, 254, 75)
        inline constexpr u32 BananaYellow = 0xfafe4b;
        /// @brief Maize rgb(244, 208, 84)
        inline constexpr u32 Maize = 0xf4d054;
        /// @brief Dull Yellow rgb(238, 220, 91)
        inline constexpr u32 DullYellow = 0xeedc5b;
        /// @brief Seafoam Blue rgb(120, 209, 182)
        inline constexpr u32 SeafoamBlue = 0x78d1b6;
        /// @brief Greenish Beige rgb(201, 209, 121)
        inline constexpr u32 GreenishBeige = 0xc9d179;
        /// @brief Orangish rgb(252, 130, 74)
        inline constexpr u32 Orangish = 0xfc824a;
        /// @brief Muted Pink rgb(209, 118, 143)
        inline constexpr u32 MutedPink = 0xd1768f;
        /// @brief Dusky Pink rgb(204, 122, 139)
        inline constexpr u32 DuskyPink = 0xcc7a8b;
        /// @brief Old Rose rgb(200, 127, 137)
        inline constexpr u32 OldRose = 0xc87f89;
        /// @brief Putty rgb(190, 174, 138)
        inline constexpr u32 Putty = 0xbeae8a;
        /// @brief Light Red rgb(255, 71, 76)
        inline constexpr u32 LightRed = 0xff474c;
        /// @brief Orangeish rgb(253, 141, 73)
        inline constexpr u32 Orangeish = 0xfd8d49;
        /// @brief Light Orange rgb(253, 170, 72)
        inline constexpr u32 LightOrange = 0xfdaa48;
        /// @brief Greenish Tan rgb(188, 203, 122)
        inline constexpr u32 GreenishTan = 0xbccb7a;
        /// @brief Dirty Pink rgb(202, 123, 128)
        inline constexpr u32 DirtyPink = 0xca7b80;
        /// @brief Barbie Pink rgb(254, 70, 165)
        inline constexpr u32 BarbiePink = 0xfe46a5;
        /// @brief Butterscotch rgb(253, 177, 71)
        inline constexpr u32 Butterscotch = 0xfdb147;
        /// @brief Watermelon rgb(253, 70, 89)
        inline constexpr u32 Watermelon = 0xfd4659;
        /// @brief Heliotrope rgb(217, 79, 245)
        inline constexpr u32 Heliotrope = 0xd94ff5;
        /// @brief Toupe rgb(199, 172, 125)
        inline constexpr u32 Toupe = 0xc7ac7d;
        /// @brief Lightish Green rgb(97, 225, 96)
        inline constexpr u32 LightishGreen = 0x61e160;
        /// @brief Ugly Pink rgb(205, 117, 132)
        inline constexpr u32 UglyPink = 0xcd7584;
        /// @brief Mushroom rgb(186, 158, 136)
        inline constexpr u32 Mushroom = 0xba9e88;
        /// @brief Canary Yellow rgb(255, 254, 64)
        inline constexpr u32 CanaryYellow = 0xfffe40;
        /// @brief Bright Cyan rgb(65, 253, 254)
        inline constexpr u32 BrightCyan = 0x41fdfe;
        /// @brief Tan rgb(209, 178, 111)
        inline constexpr u32 Tan = 0xd1b26f;
        /// @brief Old Pink rgb(199, 121, 134)
        inline constexpr u32 OldPink = 0xc77986;
        /// @brief Wisteria rgb(168, 125, 194)
        inline constexpr u32 Wisteria = 0xa87dc2;
        /// @brief Faded Orange rgb(240, 148, 77)
        inline constexpr u32 FadedOrange = 0xf0944d;
        /// @brief Pale Magenta rgb(215, 103, 173)
        inline constexpr u32 PaleMagenta = 0xd767ad;
        /// @brief Pinkish rgb(212, 106, 126)
        inline constexpr u32 Pinkish = 0xd46a7e;
        /// @brief Sandstone rgb(201, 174, 116)
        inline constexpr u32 Sandstone = 0xc9ae74;
        /// @brief Light Moss Green rgb(166, 200, 117)
        inline constexpr u32 LightMossGreen = 0xa6c875;
        /// @brief Orchid rgb(200, 117, 196)
        inline constexpr u32 Orchid = 0xc875c4;
        /// @brief Greyish rgb(168, 164, 149)
        inline constexpr u32 Greyish = 0xa8a495;
        /// @brief Yellow Green rgb(200, 253, 61)
        inline constexpr u32 YellowGreen = 0xc8fd3d;
        /// @brief Lightish Blue rgb(61, 122, 253)
        inline constexpr u32 LightishBlue = 0x3d7afd;
        /// @brief Dodger Blue rgb(62, 130, 252)
        inline constexpr u32 DodgerBlue = 0x3e82fc;
        /// @brief Purpley rgb(135, 86, 228)
        inline constexpr u32 Purpley = 0x8756e4;
        /// @brief Dark Peach rgb(222, 126, 93)
        inline constexpr u32 DarkPeach = 0xde7e5d;
        /// @brief Brownish Pink rgb(194, 126, 121)
        inline constexpr u32 BrownishPink = 0xc27e79;
        /// @brief Taupe rgb(185, 162, 129)
        inline constexpr u32 Taupe = 0xb9a281;
        /// @brief Bland rgb(175, 168, 139)
        inline constexpr u32 Bland = 0xafa88b;
        /// @brief Greenish Grey rgb(150, 174, 141)
        inline constexpr u32 GreenishGrey = 0x96ae8d;
        /// @brief Cool Grey rgb(149, 163, 166)
        inline constexpr u32 CoolGrey = 0x95a3a6;
        /// @brief Lightish Purple rgb(165, 82, 230)
        inline constexpr u32 LightishPurple = 0xa552e6;
        /// @brief Bluey Grey rgb(137, 160, 176)
        inline constexpr u32 BlueyGrey = 0x89a0b0;
        /// @brief Sunshine Yellow rgb(255, 253, 55)
        inline constexpr u32 SunshineYellow = 0xfffd37;
        /// @brief Lemon Yellow rgb(253, 255, 56)
        inline constexpr u32 LemonYellow = 0xfdff38;
        /// @brief Bluegrey rgb(133, 163, 178)
        inline constexpr u32 Bluegrey = 0x85a3b2;
        /// @brief Cement rgb(165, 163, 145)
        inline constexpr u32 Cement = 0xa5a391;
        /// @brief Stone rgb(173, 165, 135)
        inline constexpr u32 Stone = 0xada587;
        /// @brief Dusty Rose rgb(192, 115, 122)
        inline constexpr u32 DustyRose = 0xc0737a;
        /// @brief Dusty Lavender rgb(172, 134, 168)
        inline constexpr u32 DustyLavender = 0xac86a8;
        /// @brief Lime rgb(170, 255, 50)
        inline constexpr u32 Lime = 0xaaff32;
        /// @brief Off Yellow rgb(241, 243, 63)
        inline constexpr u32 OffYellow = 0xf1f33f;
        /// @brief Kiwi rgb(156, 239, 67)
        inline constexpr u32 Kiwi = 0x9cef43;
        /// @brief Pastel Red rgb(219, 88, 86)
        inline constexpr u32 PastelRed = 0xdb5856;
        /// @brief Rose rgb(207, 98, 117)
        inline constexpr u32 Rose = 0xcf6275;
        /// @brief Soft Green rgb(111, 194, 118)
        inline constexpr u32 SoftGreen = 0x6fc276;
        /// @brief Lichen rgb(143, 182, 123)
        inline constexpr u32 Lichen = 0x8fb67b;
        /// @brief Heather rgb(164, 132, 172)
        inline constexpr u32 Heather = 0xa484ac;
        /// @brief Purpleish Blue rgb(97, 64, 239)
        inline constexpr u32 PurpleishBlue = 0x6140ef;
        /// @brief Dark Periwinkle rgb(102, 95, 209)
        inline constexpr u32 DarkPeriwinkle = 0x665fd1;
        /// @brief Lightish Red rgb(254, 47, 74)
        inline constexpr u32 LightishRed = 0xfe2f4a;
        /// @brief Purpleish Pink rgb(223, 78, 200)
        inline constexpr u32 PurpleishPink = 0xdf4ec8;
        /// @brief Tan Green rgb(169, 190, 112)
        inline constexpr u32 TanGreen = 0xa9be70;
        /// @brief Mango rgb(255, 166, 43)
        inline constexpr u32 Mango = 0xffa62b;
        /// @brief Bright Light Green rgb(45, 254, 84)
        inline constexpr u32 BrightLightGreen = 0x2dfe54;
        /// @brief Light Royal Blue rgb(58, 46, 254)
        inline constexpr u32 LightRoyalBlue = 0x3a2efe;
        /// @brief Reddish Pink rgb(254, 44, 84)
        inline constexpr u32 ReddishPink = 0xfe2c54;
        /// @brief Dusty Orange rgb(240, 131, 58)
        inline constexpr u32 DustyOrange = 0xf0833a;
        /// @brief Purplish Pink rgb(206, 93, 174)
        inline constexpr u32 PurplishPink = 0xce5dae;
        /// @brief Desert rgb(204, 173, 96)
        inline constexpr u32 Desert = 0xccad60;
        /// @brief Sand Brown rgb(203, 165, 96)
        inline constexpr u32 SandBrown = 0xcba560;
        /// @brief Deep Lilac rgb(150, 110, 189)
        inline constexpr u32 DeepLilac = 0x966ebd;
        /// @brief Greyblue rgb(119, 161, 181)
        inline constexpr u32 Greyblue = 0x77a1b5;
        /// @brief Sage Green rgb(136, 179, 120)
        inline constexpr u32 SageGreen = 0x88b378;
        /// @brief Greenish Cyan rgb(42, 254, 183)
        inline constexpr u32 GreenishCyan = 0x2afeb7;
        /// @brief Dark Sky Blue rgb(68, 142, 228)
        inline constexpr u32 DarkSkyBlue = 0x448ee4;
        /// @brief Light Indigo rgb(109, 90, 207)
        inline constexpr u32 LightIndigo = 0x6d5acf;
        /// @brief Yellow Green Darker rgb(192, 251, 45)
        inline constexpr u32 YellowGreenDarker = 0xc0fb2d;
        /// @brief Fresh Green rgb(105, 216, 79)
        inline constexpr u32 FreshGreen = 0x69d84f;
        /// @brief Cornflower Blue rgb(81, 112, 215)
        inline constexpr u32 CornflowerBlue = 0x5170d7;
        /// @brief Light Olive rgb(172, 191, 105)
        inline constexpr u32 LightOlive = 0xacbf69;
        /// @brief Green Yellow rgb(201, 255, 39)
        inline constexpr u32 GreenYellow = 0xc9ff27;
        /// @brief Lemon Lime rgb(191, 254, 40)
        inline constexpr u32 LemonLime = 0xbffe28;
        /// @brief Warm Blue rgb(75, 87, 219)
        inline constexpr u32 WarmBlue = 0x4b57db;
        /// @brief Pink Purple rgb(219, 75, 218)
        inline constexpr u32 PinkPurple = 0xdb4bda;
        /// @brief Pale Red rgb(217, 84, 77)
        inline constexpr u32 PaleRed = 0xd9544d;
        /// @brief Sandy Brown rgb(196, 166, 97)
        inline constexpr u32 SandyBrown = 0xc4a661;
        /// @brief Faded Green rgb(123, 178, 116)
        inline constexpr u32 FadedGreen = 0x7bb274;
        /// @brief Grey rgb(146, 149, 145)
        inline constexpr u32 Grey = 0x929591;
        /// @brief Hot Green rgb(37, 255, 41)
        inline constexpr u32 HotGreen = 0x25ff29;
        /// @brief Bright Light Blue rgb(38, 247, 253)
        inline constexpr u32 BrightLightBlue = 0x26f7fd;
        /// @brief Strawberry rgb(251, 41, 67)
        inline constexpr u32 Strawberry = 0xfb2943;
        /// @brief Red Pink rgb(250, 42, 85)
        inline constexpr u32 RedPink = 0xfa2a55;
        /// @brief Macaroni And Cheese rgb(239, 180, 53)
        inline constexpr u32 MacaroniAndCheese = 0xefb435;
        /// @brief Kiwi Green rgb(142, 229, 63)
        inline constexpr u32 KiwiGreen = 0x8ee53f;
        /// @brief Soft Purple rgb(166, 111, 181)
        inline constexpr u32 SoftPurple = 0xa66fb5;
        /// @brief Greyish Green rgb(130, 166, 125)
        inline constexpr u32 GreyishGreen = 0x82a67d;
        /// @brief Sun Yellow rgb(255, 223, 34)
        inline constexpr u32 SunYellow = 0xffdf22;
        /// @brief Electric Purple rgb(170, 35, 255)
        inline constexpr u32 ElectricPurple = 0xaa23ff;
        /// @brief Clear Blue rgb(36, 122, 253)
        inline constexpr u32 ClearBlue = 0x247afd;
        /// @brief Pinky Red rgb(252, 38, 71)
        inline constexpr u32 PinkyRed = 0xfc2647;
        /// @brief Bluish Purple rgb(112, 59, 231)
        inline constexpr u32 BluishPurple = 0x703be7;
        /// @brief Dusky Rose rgb(186, 104, 115)
        inline constexpr u32 DuskyRose = 0xba6873;
        /// @brief Sage rgb(135, 174, 115)
        inline constexpr u32 Sage = 0x87ae73;
        /// @brief Weird Green rgb(58, 229, 127)
        inline constexpr u32 WeirdGreen = 0x3ae57f;
        /// @brief Purple Pink rgb(224, 63, 216)
        inline constexpr u32 PurplePink = 0xe03fd8;
        /// @brief Darkish Pink rgb(218, 70, 125)
        inline constexpr u32 DarkishPink = 0xda467d;
        /// @brief Pinkish Purple rgb(214, 72, 215)
        inline constexpr u32 PinkishPurple = 0xd648d7;
        /// @brief Camel rgb(198, 159, 89)
        inline constexpr u32 Camel = 0xc69f59;
        /// @brief Amethyst rgb(155, 95, 192)
        inline constexpr u32 Amethyst = 0x9b5fc0;
        /// @brief Faded Blue rgb(101, 140, 187)
        inline constexpr u32 FadedBlue = 0x658cbb;
        /// @brief Dust rgb(178, 153, 110)
        inline constexpr u32 Dust = 0xb2996e;
        /// @brief Pale Brown rgb(177, 145, 110)
        inline constexpr u32 PaleBrown = 0xb1916e;
        /// @brief Mauve rgb(174, 113, 129)
        inline constexpr u32 Mauve = 0xae7181;
        /// @brief Orangey Red rgb(250, 66, 36)
        inline constexpr u32 OrangeyRed = 0xfa4224;
        /// @brief Dark Coral rgb(207, 82, 78)
        inline constexpr u32 DarkCoral = 0xcf524e;
        /// @brief Grey Green rgb(134, 161, 125)
        inline constexpr u32 GreyGreen = 0x86a17d;
        /// @brief Lime Yellow rgb(208, 254, 29)
        inline constexpr u32 LimeYellow = 0xd0fe1d;
        /// @brief Orange Red rgb(253, 65, 30)
        inline constexpr u32 OrangeRed = 0xfd411e;
        /// @brief Purpley Blue rgb(95, 52, 231)
        inline constexpr u32 PurpleyBlue = 0x5f34e7;
        /// @brief Faded Red rgb(211, 73, 78)
        inline constexpr u32 FadedRed = 0xd3494e;
        /// @brief Dark Salmon rgb(200, 90, 83)
        inline constexpr u32 DarkSalmon = 0xc85a53;
        /// @brief Iris rgb(98, 88, 196)
        inline constexpr u32 Iris = 0x6258c4;
        /// @brief Light Olive Green rgb(164, 190, 92)
        inline constexpr u32 LightOliveGreen = 0xa4be5c;
        /// @brief Dusty Green rgb(118, 169, 115)
        inline constexpr u32 DustyGreen = 0x76a973;
        /// @brief Greeny Grey rgb(126, 160, 122)
        inline constexpr u32 GreenyGrey = 0x7ea07a;
        /// @brief Warm Grey rgb(151, 138, 132)
        inline constexpr u32 WarmGrey = 0x978a84;
        /// @brief Radioactive Green rgb(44, 250, 31)
        inline constexpr u32 RadioactiveGreen = 0x2cfa1f;
        /// @brief Wintergreen rgb(32, 249, 134)
        inline constexpr u32 Wintergreen = 0x20f986;
        /// @brief Yellowy Green rgb(191, 241, 40)
        inline constexpr u32 YellowyGreen = 0xbff128;
        /// @brief Purplish Blue rgb(96, 30, 249)
        inline constexpr u32 PurplishBlue = 0x601ef9;
        /// @brief Blue Grey rgb(117, 141, 163)
        inline constexpr u32 BlueGrey = 0x758da3;
        /// @brief Sunny Yellow rgb(255, 249, 23)
        inline constexpr u32 SunnyYellow = 0xfff917;
        /// @brief Spearmint rgb(30, 248, 118)
        inline constexpr u32 Spearmint = 0x1ef876;
        /// @brief Tomato rgb(239, 64, 38)
        inline constexpr u32 Tomato = 0xef4026;
        /// @brief Purple Blue rgb(99, 45, 233)
        inline constexpr u32 PurpleBlue = 0x632de9;
        /// @brief Aqua Marine rgb(46, 232, 187)
        inline constexpr u32 AquaMarine = 0x2ee8bb;
        /// @brief Burple rgb(104, 50, 227)
        inline constexpr u32 Burple = 0x6832e3;
        /// @brief Pinky Purple rgb(201, 76, 190)
        inline constexpr u32 PinkyPurple = 0xc94cbe;
        /// @brief Deep Lavender rgb(141, 94, 183)
        inline constexpr u32 DeepLavender = 0x8d5eb7;
        /// @brief Boring Green rgb(99, 179, 101)
        inline constexpr u32 BoringGreen = 0x63b365;
        /// @brief Yellow rgb(255, 255, 20)
        inline constexpr u32 Yellow = 0xffff14;
        /// @brief Vivid Blue rgb(21, 46, 255)
        inline constexpr u32 VividBlue = 0x152eff;
        /// @brief Golden Yellow rgb(254, 198, 21)
        inline constexpr u32 GoldenYellow = 0xfec615;
        /// @brief Reddish Orange rgb(248, 72, 28)
        inline constexpr u32 ReddishOrange = 0xf8481c;
        /// @brief Dull Orange rgb(216, 134, 59)
        inline constexpr u32 DullOrange = 0xd8863b;
        /// @brief Purpley Grey rgb(148, 126, 148)
        inline constexpr u32 PurpleyGrey = 0x947e94;
        /// @brief Sunflower rgb(255, 197, 18)
        inline constexpr u32 Sunflower = 0xffc512;
        /// @brief Neon Purple rgb(188, 19, 254)
        inline constexpr u32 NeonPurple = 0xbc13fe;
        /// @brief Orangey Yellow rgb(253, 185, 21)
        inline constexpr u32 OrangeyYellow = 0xfdb915;
        /// @brief Poison Green rgb(64, 253, 20)
        inline constexpr u32 PoisonGreen = 0x40fd14;
        /// @brief Pinkish Brown rgb(177, 114, 97)
        inline constexpr u32 PinkishBrown = 0xb17261;
        /// @brief Dark Lilac rgb(156, 109, 165)
        inline constexpr u32 DarkLilac = 0x9c6da5;
        /// @brief Tea rgb(101, 171, 124)
        inline constexpr u32 Tea = 0x65ab7c;
        /// @brief Grey Blue rgb(107, 139, 164)
        inline constexpr u32 GreyBlue = 0x6b8ba4;
        /// @brief Greyish Teal rgb(113, 159, 145)
        inline constexpr u32 GreyishTeal = 0x719f91;
        /// @brief Yellowish Orange rgb(255, 171, 15)
        inline constexpr u32 YellowishOrange = 0xffab0f;
        /// @brief Orangered rgb(254, 66, 15)
        inline constexpr u32 Orangered = 0xfe420f;
        /// @brief Bright Turquoise rgb(15, 254, 249)
        inline constexpr u32 BrightTurquoise = 0x0ffef9;
        /// @brief Sickly Yellow rgb(208, 228, 41)
        inline constexpr u32 SicklyYellow = 0xd0e429;
        /// @brief Terracota rgb(203, 104, 67)
        inline constexpr u32 Terracota = 0xcb6843;
        /// @brief Deep Rose rgb(199, 71, 103)
        inline constexpr u32 DeepRose = 0xc74767;
        /// @brief Dark Beige rgb(172, 147, 98)
        inline constexpr u32 DarkBeige = 0xac9362;
        /// @brief Grey Green Darker rgb(120, 155, 115)
        inline constexpr u32 GreyGreenDarker = 0x789b73;
        /// @brief Neon Green rgb(12, 255, 12)
        inline constexpr u32 NeonGreen = 0x0cff0c;
        /// @brief Pink Purple Darker rgb(239, 29, 231)
        inline constexpr u32 PinkPurpleDarker = 0xef1de7;
        /// @brief Dark Pink rgb(203, 65, 107)
        inline constexpr u32 DarkPink = 0xcb416b;
        /// @brief Terracotta rgb(202, 102, 65)
        inline constexpr u32 Terracotta = 0xca6641;
        /// @brief Khaki rgb(170, 166, 98)
        inline constexpr u32 Khaki = 0xaaa662;
        /// @brief Bluish Grey rgb(116, 139, 151)
        inline constexpr u32 BluishGrey = 0x748b97;
        /// @brief Electric Green rgb(33, 252, 13)
        inline constexpr u32 ElectricGreen = 0x21fc0d;
        /// @brief Purply Blue rgb(102, 26, 238)
        inline constexpr u32 PurplyBlue = 0x661aee;
        /// @brief Azul rgb(29, 93, 236)
        inline constexpr u32 Azul = 0x1d5dec;
        /// @brief Toxic Green rgb(97, 222, 42)
        inline constexpr u32 ToxicGreen = 0x61de2a;
        /// @brief Dull Green rgb(116, 166, 98)
        inline constexpr u32 DullGreen = 0x74a662;
        /// @brief Reddish Grey rgb(153, 117, 112)
        inline constexpr u32 ReddishGrey = 0x997570;
        /// @brief Steel rgb(115, 133, 149)
        inline constexpr u32 Steel = 0x738595;
        /// @brief Tangerine rgb(255, 148, 8)
        inline constexpr u32 Tangerine = 0xff9408;
        /// @brief Fluorescent Green rgb(8, 255, 8)
        inline constexpr u32 FluorescentGreen = 0x08ff08;
        /// @brief Bright Magenta rgb(255, 8, 232)
        inline constexpr u32 BrightMagenta = 0xff08e8;
        /// @brief Saffron rgb(254, 178, 9)
        inline constexpr u32 Saffron = 0xfeb209;
        /// @brief Acid Green rgb(143, 254, 9)
        inline constexpr u32 AcidGreen = 0x8ffe09;
        /// @brief Bright Violet rgb(173, 10, 253)
        inline constexpr u32 BrightViolet = 0xad0afd;
        /// @brief Yellowgreen rgb(187, 249, 15)
        inline constexpr u32 Yellowgreen = 0xbbf90f;
        /// @brief Squash rgb(242, 171, 21)
        inline constexpr u32 Squash = 0xf2ab15;
        /// @brief Apple rgb(110, 203, 60)
        inline constexpr u32 Apple = 0x6ecb3c;
        /// @brief Bluey Purple rgb(98, 65, 199)
        inline constexpr u32 BlueyPurple = 0x6241c7;
        /// @brief Dark Mint rgb(72, 192, 114)
        inline constexpr u32 DarkMint = 0x48c072;
        /// @brief Turtle Green rgb(117, 184, 79)
        inline constexpr u32 TurtleGreen = 0x75b84f;
        /// @brief Dusty Blue rgb(90, 134, 173)
        inline constexpr u32 DustyBlue = 0x5a86ad;
        /// @brief Faded Purple rgb(145, 110, 153)
        inline constexpr u32 FadedPurple = 0x916e99;
        /// @brief Electric Blue rgb(6, 82, 255)
        inline constexpr u32 ElectricBlue = 0x0652ff;
        /// @brief Strong Pink rgb(255, 7, 137)
        inline constexpr u32 StrongPink = 0xff0789;
        /// @brief Neon Red rgb(255, 7, 58)
        inline constexpr u32 NeonRed = 0xff073a;
        /// @brief Amber rgb(254, 179, 8)
        inline constexpr u32 Amber = 0xfeb308;
        /// @brief Dandelion rgb(254, 223, 8)
        inline constexpr u32 Dandelion = 0xfedf08;
        /// @brief Bright Lime Green rgb(101, 254, 8)
        inline constexpr u32 BrightLimeGreen = 0x65fe08;
        /// @brief Deep Sky Blue rgb(13, 117, 248)
        inline constexpr u32 DeepSkyBlue = 0x0d75f8;
        /// @brief Blurple rgb(85, 57, 204)
        inline constexpr u32 Blurple = 0x5539cc;
        /// @brief Adobe rgb(189, 108, 72)
        inline constexpr u32 Adobe = 0xbd6c48;
        /// @brief Clay rgb(182, 106, 80)
        inline constexpr u32 Clay = 0xb66a50;
        /// @brief Neon Yellow rgb(207, 255, 4)
        inline constexpr u32 NeonYellow = 0xcfff04;
        /// @brief Electric Lime rgb(168, 255, 4)
        inline constexpr u32 ElectricLime = 0xa8ff04;
        /// @brief Bright Sea Green rgb(5, 255, 166)
        inline constexpr u32 BrightSeaGreen = 0x05ffa6;
        /// @brief Neon Blue rgb(4, 217, 255)
        inline constexpr u32 NeonBlue = 0x04d9ff;
        /// @brief Electric Pink rgb(255, 4, 144)
        inline constexpr u32 ElectricPink = 0xff0490;
        /// @brief Lime Green rgb(137, 254, 5)
        inline constexpr u32 LimeGreen = 0x89fe05;
        /// @brief Red Orange rgb(253, 60, 6)
        inline constexpr u32 RedOrange = 0xfd3c06;
        /// @brief Bright Aqua rgb(11, 249, 234)
        inline constexpr u32 BrightAqua = 0x0bf9ea;
        /// @brief Purple Pink Darker rgb(215, 37, 222)
        inline constexpr u32 PurplePinkDarker = 0xd725de;
        /// @brief Terra Cotta rgb(201, 100, 59)
        inline constexpr u32 TerraCotta = 0xc9643b;
        /// @brief Purpley Pink rgb(200, 60, 185)
        inline constexpr u32 PurpleyPink = 0xc83cb9;
        /// @brief Reddish rgb(196, 66, 64)
        inline constexpr u32 Reddish = 0xc44240;
        /// @brief Dark Pastel Green rgb(86, 174, 87)
        inline constexpr u32 DarkPastelGreen = 0x56ae57;
        /// @brief Off Blue rgb(86, 132, 174)
        inline constexpr u32 OffBlue = 0x5684ae;
        /// @brief Sunflower Yellow rgb(255, 218, 3)
        inline constexpr u32 SunflowerYellow = 0xffda03;
        /// @brief Fluro Green rgb(10, 255, 2)
        inline constexpr u32 FluroGreen = 0x0aff02;
        /// @brief Hot Pink rgb(255, 2, 141)
        inline constexpr u32 HotPink = 0xff028d;
        /// @brief Blood Orange rgb(254, 75, 3)
        inline constexpr u32 BloodOrange = 0xfe4b03;
        /// @brief Bright Lime rgb(135, 253, 5)
        inline constexpr u32 BrightLime = 0x87fd05;
        /// @brief Marigold rgb(252, 192, 6)
        inline constexpr u32 Marigold = 0xfcc006;
        /// @brief Highlighter Green rgb(27, 252, 6)
        inline constexpr u32 HighlighterGreen = 0x1bfc06;
        /// @brief Pumpkin Orange rgb(251, 125, 7)
        inline constexpr u32 PumpkinOrange = 0xfb7d07;
        /// @brief Golden Rod rgb(249, 188, 8)
        inline constexpr u32 GoldenRod = 0xf9bc08;
        /// @brief Chartreuse rgb(193, 248, 10)
        inline constexpr u32 Chartreuse = 0xc1f80a;
        /// @brief Minty Green rgb(11, 247, 125)
        inline constexpr u32 MintyGreen = 0x0bf77d;
        /// @brief Blue With A Hint Of Purple rgb(83, 60, 198)
        inline constexpr u32 BlueWithAHintOfPurple = 0x533cc6;
        /// @brief Dusty Red rgb(185, 72, 78)
        inline constexpr u32 DustyRed = 0xb9484e;
        /// @brief Cool Blue rgb(73, 132, 184)
        inline constexpr u32 CoolBlue = 0x4984b8;
        /// @brief Asparagus rgb(119, 171, 86)
        inline constexpr u32 Asparagus = 0x77ab56;
        /// @brief Dark Sand rgb(168, 143, 89)
        inline constexpr u32 DarkSand = 0xa88f59;
        /// @brief Green Grey rgb(119, 146, 111)
        inline constexpr u32 GreenGrey = 0x77926f;
        /// @brief Greyish Purple rgb(136, 113, 145)
        inline constexpr u32 GreyishPurple = 0x887191;
        /// @brief Bright Orange rgb(255, 91, 0)
        inline constexpr u32 BrightOrange = 0xff5b00;
        /// @brief Orange Yellow rgb(255, 173, 1)
        inline constexpr u32 OrangeYellow = 0xffad01;
        /// @brief Bright Yellow rgb(255, 253, 1)
        inline constexpr u32 BrightYellow = 0xfffd01;
        /// @brief Bright Yellow Green rgb(157, 255, 0)
        inline constexpr u32 BrightYellowGreen = 0x9dff00;
        /// @brief Bright Green rgb(1, 255, 7)
        inline constexpr u32 BrightGreen = 0x01ff07;
        /// @brief Cyan rgb(0, 255, 255)
        inline constexpr u32 Cyan = 0x00ffff;
        /// @brief Bright Red rgb(255, 0, 13)
        inline constexpr u32 BrightRed = 0xff000d;
        /// @brief Bright Pink rgb(254, 1, 177)
        inline constexpr u32 BrightPink = 0xfe01b1;
        /// @brief Neon Pink rgb(254, 1, 154)
        inline constexpr u32 NeonPink = 0xfe019a;
        /// @brief Bright Sky Blue rgb(2, 204, 254)
        inline constexpr u32 BrightSkyBlue = 0x02ccfe;
        /// @brief Shocking Pink rgb(254, 2, 162)
        inline constexpr u32 ShockingPink = 0xfe02a2;
        /// @brief Greenish Yellow rgb(205, 253, 2)
        inline constexpr u32 GreenishYellow = 0xcdfd02;
        /// @brief Bright Purple rgb(190, 3, 253)
        inline constexpr u32 BrightPurple = 0xbe03fd;
        /// @brief Goldenrod rgb(250, 194, 5)
        inline constexpr u32 Goldenrod = 0xfac205;
        /// @brief Orange rgb(249, 115, 6)
        inline constexpr u32 Orange = 0xf97306;
        /// @brief Greeny Yellow rgb(198, 248, 8)
        inline constexpr u32 GreenyYellow = 0xc6f808;
        /// @brief Vermillion rgb(244, 50, 12)
        inline constexpr u32 Vermillion = 0xf4320c;
        /// @brief Vivid Green rgb(47, 239, 16)
        inline constexpr u32 VividGreen = 0x2fef10;
        /// @brief Algae rgb(84, 172, 104)
        inline constexpr u32 Algae = 0x54ac68;
        /// @brief Dark Lavender rgb(133, 103, 152)
        inline constexpr u32 DarkLavender = 0x856798;
        /// @brief Fire Engine Red rgb(254, 0, 2)
        inline constexpr u32 FireEngineRed = 0xfe0002;
        /// @brief Yellow Orange rgb(252, 176, 1)
        inline constexpr u32 YellowOrange = 0xfcb001;
        /// @brief Bright Blue rgb(1, 101, 252)
        inline constexpr u32 BrightBlue = 0x0165fc;
        /// @brief Primary Blue rgb(8, 4, 249)
        inline constexpr u32 PrimaryBlue = 0x0804f9;
        /// @brief Strong Blue rgb(12, 6, 247)
        inline constexpr u32 StrongBlue = 0x0c06f7;
        /// @brief Pinkish Red rgb(241, 12, 69)
        inline constexpr u32 PinkishRed = 0xf10c45;
        /// @brief Aqua rgb(19, 234, 201)
        inline constexpr u32 Aqua = 0x13eac9;
        /// @brief Dark Rose rgb(181, 72, 93)
        inline constexpr u32 DarkRose = 0xb5485d;
        /// @brief Light Brown rgb(173, 129, 80)
        inline constexpr u32 LightBrown = 0xad8150;
        /// @brief Dull Teal rgb(95, 158, 143)
        inline constexpr u32 DullTeal = 0x5f9e8f;
        /// @brief Greenish Turquoise rgb(0, 251, 176)
        inline constexpr u32 GreenishTurquoise = 0x00fbb0;
        /// @brief Rich Blue rgb(2, 27, 249)
        inline constexpr u32 RichBlue = 0x021bf9;
        /// @brief Vibrant Blue rgb(3, 57, 248)
        inline constexpr u32 VibrantBlue = 0x0339f8;
        /// @brief Green Apple rgb(94, 220, 31)
        inline constexpr u32 GreenApple = 0x5edc1f;
        /// @brief Greyish Blue rgb(94, 129, 157)
        inline constexpr u32 GreyishBlue = 0x5e819d;
        /// @brief Medium Grey rgb(125, 127, 124)
        inline constexpr u32 MediumGrey = 0x7d7f7c;
        /// @brief Vivid Purple rgb(153, 0, 250)
        inline constexpr u32 VividPurple = 0x9900fa;
        /// @brief Bright Teal rgb(1, 249, 198)
        inline constexpr u32 BrightTeal = 0x01f9c6;
        /// @brief Lemon Green rgb(173, 248, 2)
        inline constexpr u32 LemonGreen = 0xadf802;
        /// @brief Cherry Red rgb(247, 2, 42)
        inline constexpr u32 CherryRed = 0xf7022a;
        /// @brief Hot Magenta rgb(245, 4, 201)
        inline constexpr u32 HotMagenta = 0xf504c9;
        /// @brief Orangish Red rgb(244, 54, 5)
        inline constexpr u32 OrangishRed = 0xf43605;
        /// @brief Pink Red rgb(245, 5, 79)
        inline constexpr u32 PinkRed = 0xf5054f;
        /// @brief Azure rgb(6, 154, 243)
        inline constexpr u32 Azure = 0x069af3;
        /// @brief Fuchsia rgb(237, 13, 217)
        inline constexpr u32 Fuchsia = 0xed0dd9;
        /// @brief Dull Red rgb(187, 63, 63)
        inline constexpr u32 DullRed = 0xbb3f3f;
        /// @brief Dark Tan rgb(175, 136, 74)
        inline constexpr u32 DarkTan = 0xaf884a;
        /// @brief Fern rgb(99, 169, 80)
        inline constexpr u32 Fern = 0x63a950;
        /// @brief Grey Teal rgb(94, 155, 138)
        inline constexpr u32 GreyTeal = 0x5e9b8a;
        /// @brief Grey Purple rgb(130, 109, 140)
        inline constexpr u32 GreyPurple = 0x826d8c;
        /// @brief Steel Grey rgb(111, 130, 138)
        inline constexpr u32 SteelGrey = 0x6f828a;
        /// @brief Golden rgb(245, 191, 3)
        inline constexpr u32 Golden = 0xf5bf03;
        /// @brief Turquoise Green rgb(4, 244, 137)
        inline constexpr u32 TurquoiseGreen = 0x04f489;
        /// @brief Violet rgb(154, 14, 234)
        inline constexpr u32 Violet = 0x9a0eea;
        /// @brief Blue Purple rgb(87, 41, 206)
        inline constexpr u32 BluePurple = 0x5729ce;
        /// @brief Windows Blue rgb(55, 120, 191)
        inline constexpr u32 WindowsBlue = 0x3778bf;
        /// @brief Tan Brown rgb(171, 126, 76)
        inline constexpr u32 TanBrown = 0xab7e4c;
        /// @brief Puce rgb(165, 126, 82)
        inline constexpr u32 Puce = 0xa57e52;
        /// @brief Hot Purple rgb(203, 0, 245)
        inline constexpr u32 HotPurple = 0xcb00f5;
        /// @brief Blue Purple Darker rgb(90, 6, 239)
        inline constexpr u32 BluePurpleDarker = 0x5a06ef;
        /// @brief Piss Yellow rgb(221, 214, 24)
        inline constexpr u32 PissYellow = 0xddd618;
        /// @brief Greeny Blue rgb(66, 179, 149)
        inline constexpr u32 GreenyBlue = 0x42b395;
        /// @brief Off Green rgb(107, 163, 83)
        inline constexpr u32 OffGreen = 0x6ba353;
        /// @brief Light Plum rgb(157, 87, 131)
        inline constexpr u32 LightPlum = 0x9d5783;
        /// @brief Brown Grey rgb(141, 132, 104)
        inline constexpr u32 BrownGrey = 0x8d8468;
        /// @brief Purple Grey rgb(134, 111, 133)
        inline constexpr u32 PurpleGrey = 0x866f85;
        /// @brief Cerulean Blue rgb(5, 110, 238)
        inline constexpr u32 CeruleanBlue = 0x056eee;
        /// @brief Aqua Green rgb(18, 225, 147)
        inline constexpr u32 AquaGreen = 0x12e193;
        /// @brief Yellowish Green rgb(176, 221, 22)
        inline constexpr u32 YellowishGreen = 0xb0dd16;
        /// @brief Apple Green rgb(118, 205, 38)
        inline constexpr u32 AppleGreen = 0x76cd26;
        /// @brief Brownish rgb(156, 109, 87)
        inline constexpr u32 Brownish = 0x9c6d57;
        /// @brief Steel Blue rgb(90, 125, 154)
        inline constexpr u32 SteelBlue = 0x5a7d9a;
        /// @brief Slate Blue rgb(91, 124, 153)
        inline constexpr u32 SlateBlue = 0x5b7c99;
        /// @brief Purple Blue Darker rgb(93, 33, 208)
        inline constexpr u32 PurpleBlueDarker = 0x5d21d0;
        /// @brief Greenish Teal rgb(50, 191, 132)
        inline constexpr u32 GreenishTeal = 0x32bf84;
        /// @brief Leafy Green rgb(81, 183, 59)
        inline constexpr u32 LeafyGreen = 0x51b73b;
        /// @brief Booger rgb(155, 181, 60)
        inline constexpr u32 Booger = 0x9bb53c;
        /// @brief Nasty Green rgb(112, 178, 63)
        inline constexpr u32 NastyGreen = 0x70b23f;
        /// @brief Purply rgb(152, 63, 178)
        inline constexpr u32 Purply = 0x983fb2;
        /// @brief Coffee rgb(166, 129, 76)
        inline constexpr u32 Coffee = 0xa6814c;
        /// @brief Muted Green rgb(95, 160, 82)
        inline constexpr u32 MutedGreen = 0x5fa052;
        /// @brief Moss rgb(118, 153, 88)
        inline constexpr u32 Moss = 0x769958;
        /// @brief Grey Blue Darker rgb(100, 125, 142)
        inline constexpr u32 GreyBlueDarker = 0x647d8e;
        /// @brief Slate Green rgb(101, 141, 109)
        inline constexpr u32 SlateGreen = 0x658d6d;
        /// @brief Blue Violet rgb(93, 6, 233)
        inline constexpr u32 BlueViolet = 0x5d06e9;
        /// @brief Clay Brown rgb(178, 113, 61)
        inline constexpr u32 ClayBrown = 0xb2713d;
        /// @brief French Blue rgb(67, 107, 173)
        inline constexpr u32 FrenchBlue = 0x436bad;
        /// @brief Dark Khaki rgb(155, 143, 85)
        inline constexpr u32 DarkKhaki = 0x9b8f55;
        /// @brief Battleship Grey rgb(107, 124, 133)
        inline constexpr u32 BattleshipGrey = 0x6b7c85;
        /// @brief Tomato Red rgb(236, 45, 1)
        inline constexpr u32 TomatoRed = 0xec2d01;
        /// @brief Brownish Orange rgb(203, 119, 35)
        inline constexpr u32 BrownishOrange = 0xcb7723;
        /// @brief Dark Seafoam Green rgb(62, 175, 118)
        inline constexpr u32 DarkSeafoamGreen = 0x3eaf76;
        /// @brief Mid Green rgb(80, 167, 71)
        inline constexpr u32 MidGreen = 0x50a747;
        /// @brief Mocha rgb(157, 118, 81)
        inline constexpr u32 Mocha = 0x9d7651;
        /// @brief Purpleish rgb(152, 86, 141)
        inline constexpr u32 Purpleish = 0x98568d;
        /// @brief Blue Grey Darker rgb(96, 124, 142)
        inline constexpr u32 BlueGreyDarker = 0x607c8e;
        /// @brief Aqua Blue rgb(2, 216, 233)
        inline constexpr u32 AquaBlue = 0x02d8e9;
        /// @brief Lipstick rgb(213, 23, 78)
        inline constexpr u32 Lipstick = 0xd5174e;
        /// @brief Cool Green rgb(51, 184, 100)
        inline constexpr u32 CoolGreen = 0x33b864;
        /// @brief Stormy Blue rgb(80, 123, 156)
        inline constexpr u32 StormyBlue = 0x507b9c;
        /// @brief Cerise rgb(222, 12, 98)
        inline constexpr u32 Cerise = 0xde0c62;
        /// @brief Seaweed rgb(24, 209, 123)
        inline constexpr u32 Seaweed = 0x18d17b;
        /// @brief Blue Blue rgb(34, 66, 199)
        inline constexpr u32 BlueBlue = 0x2242c7;
        /// @brief Light Burgundy rgb(168, 65, 91)
        inline constexpr u32 LightBurgundy = 0xa8415b;
        /// @brief Light Maroon rgb(162, 72, 87)
        inline constexpr u32 LightMaroon = 0xa24857;
        /// @brief Flat Green rgb(105, 157, 76)
        inline constexpr u32 FlatGreen = 0x699d4c;
        /// @brief Purplish rgb(148, 86, 140)
        inline constexpr u32 Purplish = 0x94568c;
        /// @brief Gold rgb(219, 180, 12)
        inline constexpr u32 Gold = 0xdbb40c;
        /// @brief Tealish Green rgb(12, 220, 115)
        inline constexpr u32 TealishGreen = 0x0cdc73;
        /// @brief Greenblue rgb(35, 196, 139)
        inline constexpr u32 Greenblue = 0x23c48b;
        /// @brief Medium Blue rgb(44, 111, 187)
        inline constexpr u32 MediumBlue = 0x2c6fbb;
        /// @brief Ugly Purple rgb(164, 66, 160)
        inline constexpr u32 UglyPurple = 0xa442a0;
        /// @brief Purplish Grey rgb(122, 104, 127)
        inline constexpr u32 PurplishGrey = 0x7a687f;
        /// @brief Red rgb(229, 0, 0)
        inline constexpr u32 Red = 0xe50000;
        /// @brief Vibrant Green rgb(10, 221, 8)
        inline constexpr u32 VibrantGreen = 0x0add08;
        /// @brief Sick Green rgb(157, 185, 44)
        inline constexpr u32 SickGreen = 0x9db92c;
        /// @brief Avocado rgb(144, 177, 52)
        inline constexpr u32 Avocado = 0x90b134;
        /// @brief Medium Green rgb(57, 173, 72)
        inline constexpr u32 MediumGreen = 0x39ad48;
        /// @brief Medium Purple rgb(158, 67, 162)
        inline constexpr u32 MediumPurple = 0x9e43a2;
        /// @brief Dull Blue rgb(73, 117, 156)
        inline constexpr u32 DullBlue = 0x49759c;
        /// @brief Drab Green rgb(116, 149, 81)
        inline constexpr u32 DrabGreen = 0x749551;
        /// @brief Dusty Purple rgb(130, 95, 135)
        inline constexpr u32 DustyPurple = 0x825f87;
        /// @brief Brownish Grey rgb(134, 119, 95)
        inline constexpr u32 BrownishGrey = 0x86775f;
        /// @brief Pure Blue rgb(2, 3, 226)
        inline constexpr u32 PureBlue = 0x0203e2;
        /// @brief Algae Green rgb(33, 195, 111)
        inline constexpr u32 AlgaeGreen = 0x21c36f;
        /// @brief Bluish rgb(41, 118, 187)
        inline constexpr u32 Bluish = 0x2976bb;
        /// @brief Flat Blue rgb(60, 115, 168)
        inline constexpr u32 FlatBlue = 0x3c73a8;
        /// @brief Greenish rgb(64, 163, 104)
        inline constexpr u32 Greenish = 0x40a368;
        /// @brief Cadet Blue rgb(78, 116, 150)
        inline constexpr u32 CadetBlue = 0x4e7496;
        /// @brief Dusky Purple rgb(137, 91, 123)
        inline constexpr u32 DuskyPurple = 0x895b7b;
        /// @brief Pumpkin rgb(225, 119, 1)
        inline constexpr u32 Pumpkin = 0xe17701;
        /// @brief Blue rgb(3, 67, 223)
        inline constexpr u32 Blue = 0x0343df;
        /// @brief Vibrant Purple rgb(173, 3, 222)
        inline constexpr u32 VibrantPurple = 0xad03de;
        /// @brief Seaweed Green rgb(53, 173, 107)
        inline constexpr u32 SeaweedGreen = 0x35ad6b;
        /// @brief Muted Purple rgb(128, 91, 135)
        inline constexpr u32 MutedPurple = 0x805b87;
        /// @brief Ultramarine Blue rgb(24, 5, 219)
        inline constexpr u32 UltramarineBlue = 0x1805db;
        /// @brief Dark Yellow rgb(213, 182, 10)
        inline constexpr u32 DarkYellow = 0xd5b60a;
        /// @brief Dark Mint Green rgb(32, 192, 115)
        inline constexpr u32 DarkMintGreen = 0x20c073;
        /// @brief Pea rgb(164, 191, 32)
        inline constexpr u32 Pea = 0xa4bf20;
        /// @brief Tealish rgb(36, 188, 168)
        inline constexpr u32 Tealish = 0x24bca8;
        /// @brief Leather rgb(172, 116, 52)
        inline constexpr u32 Leather = 0xac7434;
        /// @brief Earth rgb(162, 101, 62)
        inline constexpr u32 Earth = 0xa2653e;
        /// @brief Light Forest Green rgb(79, 145, 83)
        inline constexpr u32 LightForestGreen = 0x4f9153;
        /// @brief Deep Orange rgb(220, 77, 1)
        inline constexpr u32 DeepOrange = 0xdc4d01;
        /// @brief Burnt Yellow rgb(213, 171, 9)
        inline constexpr u32 BurntYellow = 0xd5ab09;
        /// @brief Leaf rgb(113, 170, 52)
        inline constexpr u32 Leaf = 0x71aa34;
        /// @brief Camo rgb(127, 143, 78)
        inline constexpr u32 Camo = 0x7f8f4e;
        /// @brief Metallic Blue rgb(79, 115, 142)
        inline constexpr u32 MetallicBlue = 0x4f738e;
        /// @brief Dull Purple rgb(132, 89, 126)
        inline constexpr u32 DullPurple = 0x84597e;
        /// @brief Aquamarine rgb(4, 216, 178)
        inline constexpr u32 Aquamarine = 0x04d8b2;
        /// @brief Mustard Yellow rgb(210, 189, 10)
        inline constexpr u32 MustardYellow = 0xd2bd0a;
        /// @brief Copper rgb(182, 99, 37)
        inline constexpr u32 Copper = 0xb66325;
        /// @brief Bluey Green rgb(43, 177, 121)
        inline constexpr u32 BlueyGreen = 0x2bb179;
        /// @brief Dirty Blue rgb(63, 130, 157)
        inline constexpr u32 DirtyBlue = 0x3f829d;
        /// @brief Dusky Blue rgb(71, 95, 148)
        inline constexpr u32 DuskyBlue = 0x475f94;
        /// @brief Dusty Teal rgb(76, 144, 133)
        inline constexpr u32 DustyTeal = 0x4c9085;
        /// @brief Dark Sage rgb(89, 133, 86)
        inline constexpr u32 DarkSage = 0x598556;
        /// @brief Dark Hot Pink rgb(217, 1, 102)
        inline constexpr u32 DarkHotPink = 0xd90166;
        /// @brief Water Blue rgb(14, 135, 204)
        inline constexpr u32 WaterBlue = 0x0e87cc;
        /// @brief Mid Blue rgb(39, 106, 179)
        inline constexpr u32 MidBlue = 0x276ab3;
        /// @brief Jade Green rgb(43, 175, 106)
        inline constexpr u32 JadeGreen = 0x2baf6a;
        /// @brief Grass rgb(92, 172, 45)
        inline constexpr u32 Grass = 0x5cac2d;
        /// @brief Muted Blue rgb(59, 113, 159)
        inline constexpr u32 MutedBlue = 0x3b719f;
        /// @brief Twilight rgb(78, 81, 139)
        inline constexpr u32 Twilight = 0x4e518b;
        /// @brief Green Yellow Darker rgb(181, 206, 8)
        inline constexpr u32 GreenYellowDarker = 0xb5ce08;
        /// @brief Rusty Orange rgb(205, 89, 9)
        inline constexpr u32 RustyOrange = 0xcd5909;
        /// @brief Dirty Yellow rgb(205, 197, 10)
        inline constexpr u32 DirtyYellow = 0xcdc50a;
        /// @brief Ocean Green rgb(61, 153, 115)
        inline constexpr u32 OceanGreen = 0x3d9973;
        /// @brief Blueberry rgb(70, 65, 150)
        inline constexpr u32 Blueberry = 0x464196;
        /// @brief Cerulean rgb(4, 133, 209)
        inline constexpr u32 Cerulean = 0x0485d1;
        /// @brief Gross Green rgb(160, 191, 22)
        inline constexpr u32 GrossGreen = 0xa0bf16;
        /// @brief Barney rgb(172, 29, 184)
        inline constexpr u32 Barney = 0xac1db8;
        /// @brief Dark Seafoam rgb(31, 181, 122)
        inline constexpr u32 DarkSeafoam = 0x1fb57a;
        /// @brief Sea rgb(60, 153, 146)
        inline constexpr u32 Sea = 0x3c9992;
        /// @brief Violet Blue rgb(81, 10, 201)
        inline constexpr u32 VioletBlue = 0x510ac9;
        /// @brief Vomit Yellow rgb(199, 193, 12)
        inline constexpr u32 VomitYellow = 0xc7c10c;
        /// @brief Dark Mauve rgb(135, 76, 98)
        inline constexpr u32 DarkMauve = 0x874c62;
        /// @brief Ugly Yellow rgb(208, 193, 1)
        inline constexpr u32 UglyYellow = 0xd0c101;
        /// @brief Cherry rgb(207, 2, 52)
        inline constexpr u32 Cherry = 0xcf0234;
        /// @brief Yellow Ochre rgb(203, 157, 6)
        inline constexpr u32 YellowOchre = 0xcb9d06;
        /// @brief Fern Green rgb(84, 141, 68)
        inline constexpr u32 FernGreen = 0x548d44;
        /// @brief Dull Brown rgb(135, 110, 75)
        inline constexpr u32 DullBrown = 0x876e4b;
        /// @brief Grey Brown rgb(127, 112, 83)
        inline constexpr u32 GreyBrown = 0x7f7053;
        /// @brief Mustard rgb(206, 179, 1)
        inline constexpr u32 Mustard = 0xceb301;
        /// @brief Slime Green rgb(153, 204, 4)
        inline constexpr u32 SlimeGreen = 0x99cc04;
        /// @brief Puke Yellow rgb(194, 190, 14)
        inline constexpr u32 PukeYellow = 0xc2be0e;
        /// @brief Icky Green rgb(143, 174, 34)
        inline constexpr u32 IckyGreen = 0x8fae22;
        /// @brief Dirt rgb(138, 110, 69)
        inline constexpr u32 Dirt = 0x8a6e45;
        /// @brief Dusk rgb(78, 84, 129)
        inline constexpr u32 Dusk = 0x4e5481;
        /// @brief True Blue rgb(1, 15, 204)
        inline constexpr u32 TrueBlue = 0x010fcc;
        /// @brief Dirty Orange rgb(200, 118, 6)
        inline constexpr u32 DirtyOrange = 0xc87606;
        /// @brief Topaz rgb(19, 187, 175)
        inline constexpr u32 Topaz = 0x13bbaf;
        /// @brief Sickly Green rgb(148, 178, 28)
        inline constexpr u32 SicklyGreen = 0x94b21c;
        /// @brief Denim Blue rgb(59, 91, 146)
        inline constexpr u32 DenimBlue = 0x3b5b92;
        /// @brief Light Eggplant rgb(137, 69, 133)
        inline constexpr u32 LightEggplant = 0x894585;
        /// @brief Dark Taupe rgb(127, 104, 78)
        inline constexpr u32 DarkTaupe = 0x7f684e;
        /// @brief Deep Pink rgb(203, 1, 98)
        inline constexpr u32 DeepPink = 0xcb0162;
        /// @brief Ruby rgb(202, 1, 71)
        inline constexpr u32 Ruby = 0xca0147;
        /// @brief Browny Orange rgb(202, 107, 2)
        inline constexpr u32 BrownyOrange = 0xca6b02;
        /// @brief Brownish Yellow rgb(201, 176, 3)
        inline constexpr u32 BrownishYellow = 0xc9b003;
        /// @brief Rust Orange rgb(196, 85, 8)
        inline constexpr u32 RustOrange = 0xc45508;
        /// @brief Olive Yellow rgb(194, 183, 9)
        inline constexpr u32 OliveYellow = 0xc2b709;
        /// @brief Ocher rgb(191, 155, 12)
        inline constexpr u32 Ocher = 0xbf9b0c;
        /// @brief Sapphire rgb(33, 56, 171)
        inline constexpr u32 Sapphire = 0x2138ab;
        /// @brief Avocado Green rgb(135, 169, 34)
        inline constexpr u32 AvocadoGreen = 0x87a922;
        /// @brief Ocre rgb(198, 156, 4)
        inline constexpr u32 Ocre = 0xc69c04;
        /// @brief Baby Puke Green rgb(182, 196, 6)
        inline constexpr u32 BabyPukeGreen = 0xb6c406;
        /// @brief Bile rgb(181, 195, 6)
        inline constexpr u32 Bile = 0xb5c306;
        /// @brief Turquoise Blue rgb(6, 177, 196)
        inline constexpr u32 TurquoiseBlue = 0x06b1c4;
        /// @brief Brick Orange rgb(193, 74, 9)
        inline constexpr u32 BrickOrange = 0xc14a09;
        /// @brief Indigo Blue rgb(58, 24, 177)
        inline constexpr u32 IndigoBlue = 0x3a18b1;
        /// @brief Cocoa rgb(135, 95, 66)
        inline constexpr u32 Cocoa = 0x875f42;
        /// @brief Greyish Brown rgb(122, 106, 79)
        inline constexpr u32 GreyishBrown = 0x7a6a4f;
        /// @brief Dark Orange rgb(198, 81, 2)
        inline constexpr u32 DarkOrange = 0xc65102;
        /// @brief Turquoise rgb(6, 194, 172)
        inline constexpr u32 Turquoise = 0x06c2ac;
        /// @brief Snot rgb(172, 187, 13)
        inline constexpr u32 Snot = 0xacbb0d;
        /// @brief Sienna rgb(169, 86, 30)
        inline constexpr u32 Sienna = 0xa9561e;
        /// @brief Teal Green rgb(37, 163, 111)
        inline constexpr u32 TealGreen = 0x25a36f;
        /// @brief Denim rgb(59, 99, 140)
        inline constexpr u32 Denim = 0x3b638c;
        /// @brief Drab rgb(130, 131, 68)
        inline constexpr u32 Drab = 0x828344;
        /// @brief Dark Gold rgb(181, 148, 16)
        inline constexpr u32 DarkGold = 0xb59410;
        /// @brief Green rgb(21, 176, 26)
        inline constexpr u32 Green = 0x15b01a;
        /// @brief Jade rgb(31, 167, 116)
        inline constexpr u32 Jade = 0x1fa774;
        /// @brief Slate Grey rgb(89, 101, 109)
        inline constexpr u32 SlateGrey = 0x59656d;
        /// @brief Shamrock Green rgb(2, 193, 77)
        inline constexpr u32 ShamrockGreen = 0x02c14d;
        /// @brief Ochre rgb(191, 144, 5)
        inline constexpr u32 Ochre = 0xbf9005;
        /// @brief Muddy Yellow rgb(191, 172, 5)
        inline constexpr u32 MuddyYellow = 0xbfac05;
        /// @brief Frog Green rgb(88, 188, 8)
        inline constexpr u32 FrogGreen = 0x58bc08;
        /// @brief Brick rgb(160, 54, 35)
        inline constexpr u32 Brick = 0xa03623;
        /// @brief Sepia rgb(152, 94, 43)
        inline constexpr u32 Sepia = 0x985e2b;
        /// @brief Warm Purple rgb(149, 46, 143)
        inline constexpr u32 WarmPurple = 0x952e8f;
        /// @brief Moss Green rgb(101, 139, 56)
        inline constexpr u32 MossGreen = 0x658b38;
        /// @brief Slate rgb(81, 101, 114)
        inline constexpr u32 Slate = 0x516572;
        /// @brief Snot Green rgb(157, 193, 0)
        inline constexpr u32 SnotGreen = 0x9dc100;
        /// @brief Magenta rgb(194, 0, 120)
        inline constexpr u32 Magenta = 0xc20078;
        /// @brief Burnt Orange rgb(192, 78, 1)
        inline constexpr u32 BurntOrange = 0xc04e01;
        /// @brief Green Blue rgb(1, 192, 141)
        inline constexpr u32 GreenBlue = 0x01c08d;
        /// @brief Lipstick Red rgb(192, 2, 47)
        inline constexpr u32 LipstickRed = 0xc0022f;
        /// @brief Green Teal rgb(12, 181, 119)
        inline constexpr u32 GreenTeal = 0x0cb577;
        /// @brief Brownish Red rgb(158, 54, 35)
        inline constexpr u32 BrownishRed = 0x9e3623;
        /// @brief Rose Red rgb(190, 1, 60)
        inline constexpr u32 RoseRed = 0xbe013c;
        /// @brief Scarlet rgb(190, 1, 25)
        inline constexpr u32 Scarlet = 0xbe0119;
        /// @brief Bright Olive rgb(156, 187, 4)
        inline constexpr u32 BrightOlive = 0x9cbb04;
        /// @brief Burnt Sienna rgb(176, 78, 15)
        inline constexpr u32 BurntSienna = 0xb04e0f;
        /// @brief Nice Blue rgb(16, 122, 176)
        inline constexpr u32 NiceBlue = 0x107ab0;
        /// @brief Khaki Green rgb(114, 134, 57)
        inline constexpr u32 KhakiGreen = 0x728639;
        /// @brief Orange Brown rgb(190, 100, 0)
        inline constexpr u32 OrangeBrown = 0xbe6400;
        /// @brief Dark Lime Green rgb(126, 189, 1)
        inline constexpr u32 DarkLimeGreen = 0x7ebd01;
        /// @brief Pea Green rgb(142, 171, 18)
        inline constexpr u32 PeaGreen = 0x8eab12;
        /// @brief Rouge rgb(171, 18, 57)
        inline constexpr u32 Rouge = 0xab1239;
        /// @brief Pea Soup Green rgb(148, 166, 23)
        inline constexpr u32 PeaSoupGreen = 0x94a617;
        /// @brief Bruise rgb(126, 64, 113)
        inline constexpr u32 Bruise = 0x7e4071;
        /// @brief Dirty Purple rgb(115, 74, 101)
        inline constexpr u32 DirtyPurple = 0x734a65;
        /// @brief Brown Orange rgb(185, 105, 2)
        inline constexpr u32 BrownOrange = 0xb96902;
        /// @brief Rusty Red rgb(175, 47, 13)
        inline constexpr u32 RustyRed = 0xaf2f0d;
        /// @brief Ugly Blue rgb(49, 102, 138)
        inline constexpr u32 UglyBlue = 0x31668a;
        /// @brief Dirt Brown rgb(131, 101, 57)
        inline constexpr u32 DirtBrown = 0x836539;
        /// @brief Swamp rgb(105, 131, 57)
        inline constexpr u32 Swamp = 0x698339;
        /// @brief Burnt Siena rgb(183, 82, 3)
        inline constexpr u32 BurntSiena = 0xb75203;
        /// @brief Mustard Green rgb(168, 181, 4)
        inline constexpr u32 MustardGreen = 0xa8b504;
        /// @brief Green Blue Darker rgb(6, 180, 139)
        inline constexpr u32 GreenBlueDarker = 0x06b48b;
        /// @brief Yellowy Brown rgb(174, 139, 12)
        inline constexpr u32 YellowyBrown = 0xae8b0c;
        /// @brief Baby Shit Brown rgb(173, 144, 13)
        inline constexpr u32 BabyShitBrown = 0xad900d;
        /// @brief Vomit rgb(162, 164, 21)
        inline constexpr u32 Vomit = 0xa2a415;
        /// @brief Purple rgb(126, 30, 156)
        inline constexpr u32 Purple = 0x7e1e9c;
        /// @brief Military Green rgb(102, 124, 62)
        inline constexpr u32 MilitaryGreen = 0x667c3e;
        /// @brief Gunmetal rgb(83, 98, 103)
        inline constexpr u32 Gunmetal = 0x536267;
        /// @brief Yellow Brown rgb(183, 148, 0)
        inline constexpr u32 YellowBrown = 0xb79400;
        /// @brief Dark Lime rgb(132, 183, 1)
        inline constexpr u32 DarkLime = 0x84b701;
        /// @brief Booger Green rgb(150, 180, 3)
        inline constexpr u32 BoogerGreen = 0x96b403;
        /// @brief Brown Yellow rgb(178, 151, 5)
        inline constexpr u32 BrownYellow = 0xb29705;
        /// @brief Caramel rgb(175, 111, 9)
        inline constexpr u32 Caramel = 0xaf6f09;
        /// @brief Bluish Green rgb(16, 166, 116)
        inline constexpr u32 BluishGreen = 0x10a674;
        /// @brief Light Navy Blue rgb(46, 90, 136)
        inline constexpr u32 LightNavyBlue = 0x2e5a88;
        /// @brief Brownish Purple rgb(118, 66, 78)
        inline constexpr u32 BrownishPurple = 0x76424e;
        /// @brief Shamrock rgb(1, 180, 76)
        inline constexpr u32 Shamrock = 0x01b44c;
        /// @brief Orangish Brown rgb(178, 95, 3)
        inline constexpr u32 OrangishBrown = 0xb25f03;
        /// @brief Purplish Red rgb(176, 5, 75)
        inline constexpr u32 PurplishRed = 0xb0054b;
        /// @brief Puke Green rgb(154, 174, 7)
        inline constexpr u32 PukeGreen = 0x9aae07;
        /// @brief Golden Brown rgb(178, 122, 1)
        inline constexpr u32 GoldenBrown = 0xb27a01;
        /// @brief Orangey Brown rgb(177, 96, 2)
        inline constexpr u32 OrangeyBrown = 0xb16002;
        /// @brief Cinnamon rgb(172, 79, 6)
        inline constexpr u32 Cinnamon = 0xac4f06;
        /// @brief Dusk Blue rgb(38, 83, 141)
        inline constexpr u32 DuskBlue = 0x26538d;
        /// @brief Umber rgb(178, 100, 0)
        inline constexpr u32 Umber = 0xb26400;
        /// @brief Kermit Green rgb(92, 178, 0)
        inline constexpr u32 KermitGreen = 0x5cb200;
        /// @brief Ultramarine rgb(32, 0, 177)
        inline constexpr u32 Ultramarine = 0x2000b1;
        /// @brief Raspberry rgb(176, 1, 73)
        inline constexpr u32 Raspberry = 0xb00149;
        /// @brief Rust rgb(168, 60, 9)
        inline constexpr u32 Rust = 0xa83c09;
        /// @brief Mossy Green rgb(99, 139, 39)
        inline constexpr u32 MossyGreen = 0x638b27;
        /// @brief Mustard Brown rgb(172, 126, 4)
        inline constexpr u32 MustardBrown = 0xac7e04;
        /// @brief Baby Poo rgb(171, 144, 4)
        inline constexpr u32 BabyPoo = 0xab9004;
        /// @brief Raw Umber rgb(167, 94, 9)
        inline constexpr u32 RawUmber = 0xa75e09;
        /// @brief Viridian rgb(30, 145, 103)
        inline constexpr u32 Viridian = 0x1e9167;
        /// @brief Barf Green rgb(148, 172, 2)
        inline constexpr u32 BarfGreen = 0x94ac02;
        /// @brief Kelly Green rgb(2, 171, 46)
        inline constexpr u32 KellyGreen = 0x02ab2e;
        /// @brief Rust Red rgb(170, 39, 4)
        inline constexpr u32 RustRed = 0xaa2704;
        /// @brief Leaf Green rgb(92, 169, 4)
        inline constexpr u32 LeafGreen = 0x5ca904;
        /// @brief Royal Blue rgb(5, 4, 170)
        inline constexpr u32 RoyalBlue = 0x0504aa;
        /// @brief Dark Mustard rgb(168, 137, 5)
        inline constexpr u32 DarkMustard = 0xa88905;
        /// @brief Lawn Green rgb(77, 164, 9)
        inline constexpr u32 LawnGreen = 0x4da409;
        /// @brief Burnt Umber rgb(160, 69, 14)
        inline constexpr u32 BurntUmber = 0xa0450e;
        /// @brief Baby Shit Green rgb(136, 151, 23)
        inline constexpr u32 BabyShitGreen = 0x889717;
        /// @brief Cobalt rgb(30, 72, 143)
        inline constexpr u32 Cobalt = 0x1e488f;
        /// @brief Purplish Brown rgb(107, 66, 71)
        inline constexpr u32 PurplishBrown = 0x6b4247;
        /// @brief Darkish Red rgb(169, 3, 8)
        inline constexpr u32 DarkishRed = 0xa90308;
        /// @brief Cobalt Blue rgb(3, 10, 167)
        inline constexpr u32 CobaltBlue = 0x030aa7;
        /// @brief Blue Green rgb(15, 155, 142)
        inline constexpr u32 BlueGreen = 0x0f9b8e;
        /// @brief Dirty Green rgb(102, 126, 44)
        inline constexpr u32 DirtyGreen = 0x667e2c;
        /// @brief Bronze rgb(168, 121, 0)
        inline constexpr u32 Bronze = 0xa87900;
        /// @brief Puke rgb(165, 165, 2)
        inline constexpr u32 Puke = 0xa5a502;
        /// @brief Berry rgb(153, 15, 75)
        inline constexpr u32 Berry = 0x990f4b;
        /// @brief Olive Drab rgb(111, 118, 50)
        inline constexpr u32 OliveDrab = 0x6f7632;
        /// @brief Violet Red rgb(165, 0, 85)
        inline constexpr u32 VioletRed = 0xa50055;
        /// @brief Vomit Green rgb(137, 162, 3)
        inline constexpr u32 VomitGreen = 0x89a203;
        /// @brief Russet rgb(161, 57, 5)
        inline constexpr u32 Russet = 0xa13905;
        /// @brief Grass Green rgb(63, 155, 11)
        inline constexpr u32 GrassGreen = 0x3f9b0b;
        /// @brief Hazel rgb(142, 118, 24)
        inline constexpr u32 Hazel = 0x8e7618;
        /// @brief Muddy Green rgb(101, 116, 50)
        inline constexpr u32 MuddyGreen = 0x657432;
        /// @brief Barney Purple rgb(160, 4, 152)
        inline constexpr u32 BarneyPurple = 0xa00498;
        /// @brief Burnt Red rgb(159, 35, 5)
        inline constexpr u32 BurntRed = 0x9f2305;
        /// @brief Dark Fuchsia rgb(157, 7, 89)
        inline constexpr u32 DarkFuchsia = 0x9d0759;
        /// @brief Darkish Green rgb(40, 124, 55)
        inline constexpr u32 DarkishGreen = 0x287c37;
        /// @brief Emerald rgb(1, 160, 73)
        inline constexpr u32 Emerald = 0x01a049;
        /// @brief Deep Magenta rgb(160, 2, 92)
        inline constexpr u32 DeepMagenta = 0xa0025c;
        /// @brief Diarrhea rgb(159, 131, 3)
        inline constexpr u32 Diarrhea = 0x9f8303;
        /// @brief Red Brown rgb(139, 46, 22)
        inline constexpr u32 RedBrown = 0x8b2e16;
        /// @brief Purple Brown rgb(103, 58, 63)
        inline constexpr u32 PurpleBrown = 0x673a3f;
        /// @brief Teal Blue rgb(1, 136, 159)
        inline constexpr u32 TealBlue = 0x01889f;
        /// @brief Red Violet rgb(158, 1, 104)
        inline constexpr u32 RedViolet = 0x9e0168;
        /// @brief Carmine rgb(157, 2, 22)
        inline constexpr u32 Carmine = 0x9d0216;
        /// @brief Grassy Green rgb(65, 156, 3)
        inline constexpr u32 GrassyGreen = 0x419c03;
        /// @brief Ocean Blue rgb(3, 113, 156)
        inline constexpr u32 OceanBlue = 0x03719c;
        /// @brief Royal rgb(12, 23, 147)
        inline constexpr u32 Royal = 0x0c1793;
        /// @brief Sap Green rgb(92, 139, 21)
        inline constexpr u32 SapGreen = 0x5c8b15;
        /// @brief Grape rgb(108, 52, 97)
        inline constexpr u32 Grape = 0x6c3461;
        /// @brief Cranberry rgb(158, 0, 58)
        inline constexpr u32 Cranberry = 0x9e003a;
        /// @brief Baby Poop Green rgb(143, 152, 5)
        inline constexpr u32 BabyPoopGreen = 0x8f9805;
        /// @brief Milk Chocolate rgb(127, 78, 30)
        inline constexpr u32 MilkChocolate = 0x7f4e1e;
        /// @brief Auburn rgb(154, 48, 1)
        inline constexpr u32 Auburn = 0x9a3001;
        /// @brief Yellowish Brown rgb(155, 122, 1)
        inline constexpr u32 YellowishBrown = 0x9b7a01;
        /// @brief Mulberry rgb(146, 10, 78)
        inline constexpr u32 Mulberry = 0x920a4e;
        /// @brief Deep Red rgb(154, 2, 0)
        inline constexpr u32 DeepRed = 0x9a0200;
        /// @brief Raw Sienna rgb(154, 98, 0)
        inline constexpr u32 RawSienna = 0x9a6200;
        /// @brief Pea Soup rgb(146, 153, 1)
        inline constexpr u32 PeaSoup = 0x929901;
        /// @brief Purple Red rgb(153, 1, 71)
        inline constexpr u32 PurpleRed = 0x990147;
        /// @brief Ugly Green rgb(122, 151, 3)
        inline constexpr u32 UglyGreen = 0x7a9703;
        /// @brief Sea Blue rgb(4, 116, 149)
        inline constexpr u32 SeaBlue = 0x047495;
        /// @brief Puke Brown rgb(148, 119, 6)
        inline constexpr u32 PukeBrown = 0x947706;
        /// @brief Reddish Purple rgb(145, 9, 81)
        inline constexpr u32 ReddishPurple = 0x910951;
        /// @brief Light Navy rgb(21, 80, 132)
        inline constexpr u32 LightNavy = 0x155084;
        /// @brief Dark Magenta rgb(150, 0, 86)
        inline constexpr u32 DarkMagenta = 0x960056;
        /// @brief Blood Red rgb(152, 0, 2)
        inline constexpr u32 BloodRed = 0x980002;
        /// @brief Irish Green rgb(1, 149, 41)
        inline constexpr u32 IrishGreen = 0x019529;
        /// @brief Peacock Blue rgb(1, 103, 149)
        inline constexpr u32 PeacockBlue = 0x016795;
        /// @brief Warm Brown rgb(150, 78, 2)
        inline constexpr u32 WarmBrown = 0x964e02;
        /// @brief True Green rgb(8, 148, 4)
        inline constexpr u32 TrueGreen = 0x089404;
        /// @brief Brown Red rgb(146, 43, 5)
        inline constexpr u32 BrownRed = 0x922b05;
        /// @brief Dark Sea Green rgb(17, 135, 93)
        inline constexpr u32 DarkSeaGreen = 0x11875d;
        /// @brief Tree Green rgb(42, 126, 25)
        inline constexpr u32 TreeGreen = 0x2a7e19;
        /// @brief Teal rgb(2, 147, 134)
        inline constexpr u32 Teal = 0x029386;
        /// @brief Greenish Blue rgb(11, 139, 135)
        inline constexpr u32 GreenishBlue = 0x0b8b87;
        /// @brief Baby Poop rgb(147, 124, 0)
        inline constexpr u32 BabyPoop = 0x937c00;
        /// @brief Kelley Green rgb(0, 147, 55)
        inline constexpr u32 KelleyGreen = 0x009337;
        /// @brief Ocean rgb(1, 123, 146)
        inline constexpr u32 Ocean = 0x017b92;
        /// @brief Dark Cyan rgb(10, 136, 138)
        inline constexpr u32 DarkCyan = 0x0a888a;
        /// @brief Brick Red rgb(143, 20, 2)
        inline constexpr u32 BrickRed = 0x8f1402;
        /// @brief Dark Yellow Green rgb(114, 143, 2)
        inline constexpr u32 DarkYellowGreen = 0x728f02;
        /// @brief Emerald Green rgb(2, 143, 30)
        inline constexpr u32 EmeraldGreen = 0x028f1e;
        /// @brief Poo rgb(143, 115, 3)
        inline constexpr u32 Poo = 0x8f7303;
        /// @brief Medium Brown rgb(127, 81, 18)
        inline constexpr u32 MediumBrown = 0x7f5112;
        /// @brief Blue Green Darker rgb(19, 126, 109)
        inline constexpr u32 BlueGreenDarker = 0x137e6d;
        /// @brief Rust Brown rgb(139, 49, 3)
        inline constexpr u32 RustBrown = 0x8b3103;
        /// @brief Muddy Brown rgb(136, 104, 6)
        inline constexpr u32 MuddyBrown = 0x886806;
        /// @brief Darkish Purple rgb(117, 25, 115)
        inline constexpr u32 DarkishPurple = 0x751973;
        /// @brief Red Wine rgb(140, 0, 52)
        inline constexpr u32 RedWine = 0x8c0034;
        /// @brief Crimson rgb(140, 0, 15)
        inline constexpr u32 Crimson = 0x8c000f;
        /// @brief Poo Brown rgb(136, 95, 1)
        inline constexpr u32 PooBrown = 0x885f01;
        /// @brief Indian Red rgb(133, 14, 4)
        inline constexpr u32 IndianRed = 0x850e04;
        /// @brief Red Purple rgb(130, 7, 71)
        inline constexpr u32 RedPurple = 0x820747;
        /// @brief Reddish Brown rgb(127, 43, 10)
        inline constexpr u32 ReddishBrown = 0x7f2b0a;
        /// @brief Camo Green rgb(82, 101, 37)
        inline constexpr u32 CamoGreen = 0x526525;
        /// @brief Deep Aqua rgb(8, 120, 127)
        inline constexpr u32 DeepAqua = 0x08787f;
        /// @brief Murky Green rgb(108, 122, 14)
        inline constexpr u32 MurkyGreen = 0x6c7a0e;
        /// @brief Pine rgb(43, 93, 52)
        inline constexpr u32 Pine = 0x2b5d34;
        /// @brief Swamp Green rgb(116, 133, 0)
        inline constexpr u32 SwampGreen = 0x748500;
        /// @brief Jungle Green rgb(4, 130, 67)
        inline constexpr u32 JungleGreen = 0x048243;
        /// @brief Mud rgb(115, 92, 18)
        inline constexpr u32 Mud = 0x735c12;
        /// @brief Dark Red rgb(132, 0, 0)
        inline constexpr u32 DarkRed = 0x840000;
        /// @brief Deep Sea Blue rgb(1, 84, 130)
        inline constexpr u32 DeepSeaBlue = 0x015482;
        /// @brief Darkish Blue rgb(1, 65, 130)
        inline constexpr u32 DarkishBlue = 0x014182;
        /// @brief Indigo rgb(56, 2, 130)
        inline constexpr u32 Indigo = 0x380282;
        /// @brief Dark Grass Green rgb(56, 128, 4)
        inline constexpr u32 DarkGrassGreen = 0x388004;
        /// @brief Twilight Blue rgb(10, 67, 122)
        inline constexpr u32 TwilightBlue = 0x0a437a;
        /// @brief Olive rgb(110, 117, 14)
        inline constexpr u32 Olive = 0x6e750e;
        /// @brief Dark Grey Blue rgb(41, 70, 91)
        inline constexpr u32 DarkGreyBlue = 0x29465b;
        /// @brief Wine rgb(128, 1, 63)
        inline constexpr u32 Wine = 0x80013f;
        /// @brief Brown Green rgb(112, 108, 17)
        inline constexpr u32 BrownGreen = 0x706c11;
        /// @brief Dark Green Blue rgb(31, 99, 87)
        inline constexpr u32 DarkGreenBlue = 0x1f6357;
        /// @brief Dark Slate Blue rgb(33, 71, 97)
        inline constexpr u32 DarkSlateBlue = 0x214761;
        /// @brief Shit rgb(127, 95, 0)
        inline constexpr u32 Shit = 0x7f5f00;
        /// @brief Poop rgb(127, 94, 0)
        inline constexpr u32 Poop = 0x7f5e00;
        /// @brief Shit Green rgb(117, 128, 0)
        inline constexpr u32 ShitGreen = 0x758000;
        /// @brief Ugly Brown rgb(125, 113, 3)
        inline constexpr u32 UglyBrown = 0x7d7103;
        /// @brief Shit Brown rgb(123, 88, 4)
        inline constexpr u32 ShitBrown = 0x7b5804;
        /// @brief Wine Red rgb(123, 3, 35)
        inline constexpr u32 WineRed = 0x7b0323;
        /// @brief Olive Green rgb(103, 122, 4)
        inline constexpr u32 OliveGreen = 0x677a04;
        /// @brief Velvet rgb(117, 8, 81)
        inline constexpr u32 Velvet = 0x750851;
        /// @brief Charcoal Grey rgb(60, 65, 66)
        inline constexpr u32 CharcoalGrey = 0x3c4142;
        /// @brief Poop Green rgb(111, 124, 0)
        inline constexpr u32 PoopGreen = 0x6f7c00;
        /// @brief Bordeaux rgb(123, 0, 44)
        inline constexpr u32 Bordeaux = 0x7b002c;
        /// @brief Poop Brown rgb(122, 89, 1)
        inline constexpr u32 PoopBrown = 0x7a5901;
        /// @brief Bluegreen rgb(1, 122, 121)
        inline constexpr u32 Bluegreen = 0x017a79;
        /// @brief Greenish Brown rgb(105, 97, 18)
        inline constexpr u32 GreenishBrown = 0x696112;
        /// @brief Browny Green rgb(111, 108, 10)
        inline constexpr u32 BrownyGreen = 0x6f6c0a;
        /// @brief Prussian Blue rgb(0, 69, 119)
        inline constexpr u32 PrussianBlue = 0x004577;
        /// @brief Blood rgb(119, 0, 1)
        inline constexpr u32 Blood = 0x770001;
        /// @brief Chestnut rgb(116, 40, 2)
        inline constexpr u32 Chestnut = 0x742802;
        /// @brief Brownish Green rgb(106, 110, 9)
        inline constexpr u32 BrownishGreen = 0x6a6e09;
        /// @brief Deep Turquoise rgb(1, 115, 116)
        inline constexpr u32 DeepTurquoise = 0x017374;
        /// @brief Deep Blue rgb(4, 2, 115)
        inline constexpr u32 DeepBlue = 0x040273;
        /// @brief Merlot rgb(115, 0, 57)
        inline constexpr u32 Merlot = 0x730039;
        /// @brief Dark Aquamarine rgb(1, 115, 113)
        inline constexpr u32 DarkAquamarine = 0x017371;
        /// @brief Reddy Brown rgb(110, 16, 5)
        inline constexpr u32 ReddyBrown = 0x6e1005;
        /// @brief Camouflage Green rgb(75, 97, 19)
        inline constexpr u32 CamouflageGreen = 0x4b6113;
        /// @brief Army Green rgb(75, 93, 22)
        inline constexpr u32 ArmyGreen = 0x4b5d16;
        /// @brief Rich Purple rgb(114, 0, 88)
        inline constexpr u32 RichPurple = 0x720058;
        /// @brief Dark Royal Blue rgb(2, 6, 111)
        inline constexpr u32 DarkRoyalBlue = 0x02066f;
        /// @brief Grape Purple rgb(93, 20, 81)
        inline constexpr u32 GrapePurple = 0x5d1451;
        /// @brief Dark Aqua rgb(5, 105, 107)
        inline constexpr u32 DarkAqua = 0x05696b;
        /// @brief Greeny Brown rgb(105, 96, 6)
        inline constexpr u32 GreenyBrown = 0x696006;
        /// @brief Mud Brown rgb(96, 70, 15)
        inline constexpr u32 MudBrown = 0x60460f;
        /// @brief Royal Purple rgb(75, 0, 110)
        inline constexpr u32 RoyalPurple = 0x4b006e;
        /// @brief Dark Grey rgb(54, 55, 55)
        inline constexpr u32 DarkGrey = 0x363737;
        /// @brief Marine Blue rgb(1, 56, 106)
        inline constexpr u32 MarineBlue = 0x01386a;
        /// @brief Dark Blue Grey rgb(31, 59, 77)
        inline constexpr u32 DarkBlueGrey = 0x1f3b4d;
        /// @brief Charcoal rgb(52, 56, 55)
        inline constexpr u32 Charcoal = 0x343837;
        /// @brief Petrol rgb(0, 95, 106)
        inline constexpr u32 Petrol = 0x005f6a;
        /// @brief Spruce rgb(10, 95, 56)
        inline constexpr u32 Spruce = 0x0a5f38;
        /// @brief Claret rgb(104, 0, 24)
        inline constexpr u32 Claret = 0x680018;
        /// @brief Mud Green rgb(96, 102, 2)
        inline constexpr u32 MudGreen = 0x606602;
        /// @brief Olive Brown rgb(100, 84, 3)
        inline constexpr u32 OliveBrown = 0x645403;
        /// @brief Darkblue rgb(3, 7, 100)
        inline constexpr u32 Darkblue = 0x030764;
        /// @brief Plum rgb(88, 15, 65)
        inline constexpr u32 Plum = 0x580f41;
        /// @brief Brown rgb(101, 55, 0)
        inline constexpr u32 Brown = 0x653700;
        /// @brief Maroon rgb(101, 0, 33)
        inline constexpr u32 Maroon = 0x650021;
        /// @brief Marine rgb(4, 46, 96)
        inline constexpr u32 Marine = 0x042e60;
        /// @brief Burgundy rgb(97, 0, 35)
        inline constexpr u32 Burgundy = 0x610023;
        /// @brief Dark Turquoise rgb(4, 92, 90)
        inline constexpr u32 DarkTurquoise = 0x045c5a;
        /// @brief Forest rgb(11, 85, 9)
        inline constexpr u32 Forest = 0x0b5509;
        /// @brief Dark Indigo rgb(31, 9, 84)
        inline constexpr u32 DarkIndigo = 0x1f0954;
        /// @brief Navy Green rgb(53, 83, 10)
        inline constexpr u32 NavyGreen = 0x35530a;
        /// @brief Dark Blue rgb(0, 3, 91)
        inline constexpr u32 DarkBlue = 0x00035b;
        /// @brief Deep Green rgb(2, 89, 15)
        inline constexpr u32 DeepGreen = 0x02590f;
        /// @brief Deep Teal rgb(0, 85, 90)
        inline constexpr u32 DeepTeal = 0x00555a;
        /// @brief Green Brown rgb(84, 78, 3)
        inline constexpr u32 GreenBrown = 0x544e03;
        /// @brief Plum Purple rgb(78, 5, 80)
        inline constexpr u32 PlumPurple = 0x4e0550;
        /// @brief Dark Blue Green rgb(0, 82, 73)
        inline constexpr u32 DarkBlueGreen = 0x005249;
        /// @brief Pine Green rgb(10, 72, 30)
        inline constexpr u32 PineGreen = 0x0a481e;
        /// @brief Dark Teal rgb(1, 77, 78)
        inline constexpr u32 DarkTeal = 0x014d4e;
        /// @brief Dark Olive Green rgb(60, 77, 3)
        inline constexpr u32 DarkOliveGreen = 0x3c4d03;
        /// @brief Deep Violet rgb(73, 6, 72)
        inline constexpr u32 DeepViolet = 0x490648;
        /// @brief Bottle Green rgb(4, 74, 5)
        inline constexpr u32 BottleGreen = 0x044a05;
        /// @brief Darkgreen rgb(5, 73, 7)
        inline constexpr u32 Darkgreen = 0x054907;
        /// @brief British Racing Green rgb(5, 72, 13)
        inline constexpr u32 BritishRacingGreen = 0x05480d;
        /// @brief Forest Green rgb(6, 71, 12)
        inline constexpr u32 ForestGreen = 0x06470c;
        /// @brief Dried Blood rgb(75, 1, 1)
        inline constexpr u32 DriedBlood = 0x4b0101;
        /// @brief Night Blue rgb(4, 3, 72)
        inline constexpr u32 NightBlue = 0x040348;
        /// @brief Evergreen rgb(5, 71, 42)
        inline constexpr u32 Evergreen = 0x05472a;
        /// @brief Dark rgb(27, 36, 49)
        inline constexpr u32 Dark = 0x1b2431;
        /// @brief Mahogany rgb(74, 1, 0)
        inline constexpr u32 Mahogany = 0x4a0100;
        /// @brief Forrest Green rgb(21, 68, 6)
        inline constexpr u32 ForrestGreen = 0x154406;
        /// @brief Eggplant Purple rgb(67, 5, 65)
        inline constexpr u32 EggplantPurple = 0x430541;
        /// @brief Hunter Green rgb(11, 64, 8)
        inline constexpr u32 HunterGreen = 0x0b4008;
        /// @brief Racing Green rgb(1, 70, 0)
        inline constexpr u32 RacingGreen = 0x014600;
        /// @brief Navy Blue rgb(0, 17, 70)
        inline constexpr u32 NavyBlue = 0x001146;
        /// @brief Dark Purple rgb(53, 6, 62)
        inline constexpr u32 DarkPurple = 0x35063e;
        /// @brief Aubergine rgb(61, 7, 52)
        inline constexpr u32 Aubergine = 0x3d0734;
        /// @brief Deep Brown rgb(65, 2, 0)
        inline constexpr u32 DeepBrown = 0x410200;
        /// @brief Chocolate Brown rgb(65, 25, 0)
        inline constexpr u32 ChocolateBrown = 0x411900;
        /// @brief Dark Violet rgb(52, 1, 63)
        inline constexpr u32 DarkViolet = 0x34013f;
        /// @brief Deep Purple rgb(54, 1, 63)
        inline constexpr u32 DeepPurple = 0x36013f;
        /// @brief Dark Plum rgb(63, 1, 44)
        inline constexpr u32 DarkPlum = 0x3f012c;
        /// @brief Navy rgb(1, 21, 62)
        inline constexpr u32 Navy = 0x01153e;
        /// @brief Dark Olive rgb(55, 62, 2)
        inline constexpr u32 DarkOlive = 0x373e02;
        /// @brief Chocolate rgb(61, 28, 2)
        inline constexpr u32 Chocolate = 0x3d1c02;
        /// @brief Eggplant rgb(56, 8, 53)
        inline constexpr u32 Eggplant = 0x380835;
        /// @brief Dark Maroon rgb(60, 0, 8)
        inline constexpr u32 DarkMaroon = 0x3c0008;
        /// @brief Midnight Purple rgb(40, 1, 55)
        inline constexpr u32 MidnightPurple = 0x280137;
        /// @brief Dark Green rgb(3, 53, 0)
        inline constexpr u32 DarkGreen = 0x033500;
        /// @brief Dark Navy rgb(0, 4, 53)
        inline constexpr u32 DarkNavy = 0x000435;
        /// @brief Midnight Blue rgb(2, 0, 53)
        inline constexpr u32 MidnightBlue = 0x020035;
        /// @brief Very Dark Purple rgb(42, 1, 52)
        inline constexpr u32 VeryDarkPurple = 0x2a0134;
        /// @brief Dark Brown rgb(52, 28, 2)
        inline constexpr u32 DarkBrown = 0x341c02;
        /// @brief Very Dark Blue rgb(0, 1, 51)
        inline constexpr u32 VeryDarkBlue = 0x000133;
        /// @brief Very Dark Green rgb(6, 46, 3)
        inline constexpr u32 VeryDarkGreen = 0x062e03;
        /// @brief Dark Forest Green rgb(0, 45, 4)
        inline constexpr u32 DarkForestGreen = 0x002d04;
        /// @brief Dark Navy Blue rgb(0, 2, 46)
        inline constexpr u32 DarkNavyBlue = 0x00022e;
        /// @brief Midnight rgb(3, 1, 45)
        inline constexpr u32 Midnight = 0x03012d;
        /// @brief Very Dark Brown rgb(29, 2, 0)
        inline constexpr u32 VeryDarkBrown = 0x1d0200;
        /// @brief Almost Black rgb(7, 13, 13)
        inline constexpr u32 AlmostBlack = 0x070d0d;
        /// @brief Black rgb(0, 0, 0)
        inline constexpr u32 Black = 0x000000;
    } // namespace Color

    /// @brief This namespace contains colors used for debugging or profiling purposes.
    namespace DebugColor {
        /// @brief Used for generic purposes, shows the most important stuff
        inline constexpr u32 MainDebugColor = Color::Amber;
        /// @brief Used for generic purposes, shows important stuff
        inline constexpr u32 SecondaryDebugColor = Color::Purple;
        /// @brief Used for generic purposes, shows other stuff
        inline constexpr u32 TernaryDebugColor = Color::Teal;

        /// @brief This color should be used only if there is an important issue found
        inline constexpr u32 DangerousDebugColor = Color::CoralPink;

        /// @brief This color is the bright color for generic purposes.
        inline constexpr u32 BrightDebugColor = Color::PaleGrey;
        /// @brief This color is the dark color for generic purposes.
        /// @note It's not totally black because Tracy explicitly states that color with number 0 is the no-color
        /// selected value.
        inline constexpr u32 DarkDebugColor = Color::AlmostBlack;
    } // namespace DebugColor
} // namespace Sola::Graphics

#endif
