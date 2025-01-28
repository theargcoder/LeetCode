#include <iostream>
#include <set>
#include <vector>
// using std::multiset
// beats a  lot of the solutions pretty fast
/*
class Solution
{
  public:
    std::vector<std::vector<int> >
    threeSum (std::vector<int> &nums)
    {
        std::vector<std::vector<int> > result;
        std::multiset<int> sorted (nums.begin (), nums.end ());

        int size = sorted.size ();

        if (size < 3)
            {
                return result;
            }

        auto middle = sorted.lower_bound (0);

        auto it_first = sorted.begin ();

        if (*it_first > 0)
            return result;

        if (sorted.count (0) > 2)
            result.push_back ({ 0, 0, 0 });

        for (auto it = sorted.begin (); it != sorted.end ();)
            {
                if (*it != 0)
                    {
                        int opposite = ~(*it - 1);

                        auto start = sorted.lower_bound (*it);
                        auto end = sorted.end ();
                        start++;
                        end--;

                        while (start != end && *start < opposite
                               && *start <= *end)
                            {
                                int sum = *start + *end;
                                if (sum == opposite)
                                    {
                                        std::vector<int> yei{ *it, *start,
                                                              *end };
                                        result.push_back (yei);
                                        while (*start == yei[1])
                                            start++;
                                        while (*end == yei[2])
                                            end--;
                                    }
                                else if (sum < opposite)
                                    {
                                        int start_original = *start;
                                        while (*start == start_original)
                                            start++;
                                    }
                                else
                                    {
                                        int end_original = *end;
                                        while (*end == end_original)
                                            end--;
                                    }
                            }
                    }
                else
                    {
                        break;
                    }
                it = sorted.upper_bound (*it);
            }

        return result;
    }
};
*/
// working solution (i think its working LOL) with prints
/*
class Solution
{
  public:
    int
    threeSumClosest (std::vector<int> &nums, int target)
    {
        int result = 214748364;
        std::multiset<int> sorted (nums.begin (), nums.end ());

        std::cout << "SORTED IS " << '\n';
        for (auto i : sorted)
            {
                std::cout << i << ' ' << ',';
            }
        std::cout << '\n';


        if (sorted.size () == 3)
            {
                result = 0;
                for (auto it = sorted.begin (); it != sorted.end (); it++)
                    result += *it;

                return result;
            }

        std::cout << "made it here 1" << '\n';
        for (auto it = sorted.begin (); it != sorted.end (); it++)
            {

                        std::cout << "it -> " << *it << '\n';
                        int missing = target - *it;
                        std::cout << "missing =  " << missing << '\n';

                        auto start = sorted.lower_bound (*it);
                        auto end = sorted.end ();
                        start++;
                        end--;

                while (start != end && *start < std::abs(missing))
                            {
                                std::cout << "start -> " << *start << '\n';
                                std::cout << "end -> " << *end << '\n';
                                int sum = *start + *end;
                                int total_sum = sum + *it;
                                int diff_total_sum
                                    = std::abs (target - total_sum);
                                int diff_result = std::abs (target - result);
                                std::cout << "sum -> " << sum << '\n';
                                std::cout << "total_sum -> " << total_sum
                                          << '\n';
                                std::cout << "diff_total_sum -> "
                                          << diff_total_sum << '\n';
                                std::cout << "diff_result -> " << diff_result
                                          << '\n';
                                if (sum == missing)
                                    {
                                        return total_sum;
                                    }
                                else
                                    {
                                        if (diff_total_sum < diff_result)
                                            {
                                                result = total_sum;
                                                std::cout << "result is "
                                                          << result << '\n';
                                            }

                                        if (sum < missing)
                                            {
                                                start++;
                                            }
                                        else
                                            {
                                                end--;
                                            }
                                    }
                            }

            }

        std::cout << "LOOP HALTED NOW BRO \n\n" << '\n';

        return result;
    }
};
*/
// using std::set since duplicates don't matter here
class Solution
{
  public:
    int
    threeSumClosest (std::vector<int> &nums, int target)
    {
        int result = 214748364;
        std::multiset<int> sorted (nums.begin (), nums.end ());

        if (sorted.size () == 3)
            {
                result = 0;
                for (auto it = sorted.begin (); it != sorted.end (); it++)
                    result += *it;

                return result;
            }
        auto finish = sorted.end ();
        finish--;
        for (auto it = sorted.begin (); it != finish; it++)
            {
                int missing = target - *it;

                auto start = sorted.lower_bound (*it);
                auto end = sorted.end ();
                start++;
                end--;

                while (start != end && *start <= std::abs (missing))
                    {
                        int sum = *start + *end;
                        int total_sum = sum + *it;
                        int diff_total_sum = std::abs (target - total_sum);
                        int diff_result = std::abs (target - result);
                        if (diff_total_sum < diff_result)
                            {
                                result = total_sum;
                            }

                        if (sum < missing)
                            {
                                start++;
                            }
                        else
                            {
                                end--;
                            }
                    }
            }

        return result;
    }
};

int
main ()
{
    Solution solution;
    std::vector<std::vector<int> > inputs{
        { -1, 0, 1, 2, -1, -4 },
        { 0, 1, 1 },
        { 0, 0, 0 },
        { -1, 0, 1, 2, -1, -4, 4, 5, 2, 9, 1, 0, 2 },
        { 1, 2, 3, 4, 5, 6, 7 },
        { 45,  63,  56,  42,  103,  -79, -29, -80, -1,  -71, -78, 99,
          14,  19,  25,  -88, -102, 72,  99,  84,  100, 3,   -31, 33,
          65,  -34, 77,  39,  -36,  -89, -77, -2,  18,  30,  -28, -52,
          -26, 24,  -51, 46,  -92,  30,  76,  -31, 53,  54,  52,  -103,
          -56, -56, 61,  95,  45,   47,  39,  77,  54,  -83, -28, -100,
          -20, 77,  -36, 33,  -91,  -72, 77 },
        { 45,   63,  56,   42,   103,  -79, -29, -80, -1,  -71, -78, 99,
          14,   19,  25,   -88,  -102, 72,  99,  84,  100, 3,   -31, 33,
          65,   -34, 77,   39,   -36,  -89, -77, -2,  18,  30,  -28, -52,
          -26,  24,  -51,  46,   -92,  30,  76,  -31, 53,  54,  52,  -103,
          -56,  -56, 61,   95,   45,   47,  39,  77,  54,  -83, -28, -100,
          -20,  77,  -36,  33,   -91,  -72, 77,  -76, 27,  -16, 45,  47,
          29,   44,  46,   -76,  93,   90,  59,  -15, 54,  61,  55,  25,
          55,   48,  44,   -44,  -21,  21,  84,  99,  -13, 90,  64,  -81,
          1,    -95, -89,  -48,  24,   87,  -26, 18,  -83, 4,   66,  -40,
          -74,  -46, -101, -21,  -24,  51,  -22, -92, 58,  57,  -69, 22,
          105,  93,  29,   61,   39,   -21, 90,  86,  34,  -78, -96, -1,
          -50,  -31, 31,   -49,  -1,   7,   27,  70,  21,  101, 98,  -11,
          60,   7,   -75,  -84,  24,   3,   22,  -10, 73,  -81, 0,   65,
          49,   33,  -25,  79,   61,   64,  -83, 51,  -43, -25, -44, -20,
          -92,  64,  -89,  59,   -57,  -5,  -11, -27, 15,  36,  49,  70,
          81,   86,  -3,   85,   -60,  104, -11, -18, -14, -37, 44,  61,
          33,   52,  -11,  36,   103,  -77, 98,  -39, -23, 99,  -67, -82,
          84,   -21, 67,   70,   12,   3,   84,  -19, 100, 38,  -78, 26,
          -92,  88,  -61,  -67,  21,   -65, -79, 16,  -8,  54,  -3,  -77,
          -98,  72,  27,   90,   13,   0,   2,   93,  -28, -71, -97, -26,
          -39,  94,  8,    -91,  84,   75,  105, -38, -39, -66, 101, -64,
          38,   -57, -46,  -26,  14,   -15, -70, 69,  48,  32,  1,   -81,
          -71,  -1,  -104, 17,   19,   14,  -15, 59,  -90, -83, -75, -74,
          2,    -29, 1,    -105, 12,   30,  -21, -33, -99, 44,  -28, -2,
          -6,   -46, -77,  -13,  88,   -7,  -87, 97,  -86, -48, -76, -51,
          -75,  5,   -94,  -105, 90,   96,  24,  -1,  9,   -2,  -74, -53,
          -100, 97,  69 },
        { -83193, -24751, -49927, 43658,  8930,   -88728, -72456, -49122,
          77923,  -62291, 64440,  -61835, -15508, -56958, -92013, 22503,
          -17673, 31729,  78840,  42612,  44303,  -66831, -82291, -2843,
          29560,  70933,  -6901,  -19722, 51816,  95335,  -903,   -92174,
          -86488, 29267,  23810,  -22367, 80979,  79149,  -63421, 58821,
          11967,  -89328, 1393,   -80664, 25485,  -8255,  -74772, -5909,
          -59806, 86357,  -64999, 21153,  -83292, 57944,  15668,  71490,
          88124,  2196,   9530,   -39097, 27722,  -45334, 28549,  18024,
          97801,  -93147, 40977,  -52592, 8228,   74933,  -39702, 38981,
          -71365, -91987, -76135, 89814,  39063,  54536,  39425,  -98331,
          24115,  -79906, -24371, -53499, 46517,  34195,  -69895, -89596,
          19451,  94298,  82188,  -78877, 99505,  -53118, -93248, 31566,
          36716,  30337,  54438,  -46856, -48499, -55103, 83871,  55828,
          11137,  -80642, 53177,  82397,  22294,  -22096, -78391, 46231,
          59745,  -55825, -46365, -33702, -1858,  -19601, -72032, -9588,
          -99740, -26443, -58406, -11992, 16395,  25968,  19113,  -95470,
          -28994, 10962,  97942,  -14635, -57918, 79852,  30767,  -66179,
          85695,  -75288, 73671,  -40099, -51410, 24831,  14738,  53057,
          -68384, -80210, 55640,  10679,  -62665, -22994, -2028,  36098,
          -50905, 75319,  83454,  45223,  12289,  56760,  48905,  86126,
          -63877, 29506,  -54187, -23230, 35238,  29094,  -3780,  87844,
          12366,  40534,  25226,  15394,  41363,  18738,  -92156, 59590,
          -63450, 45159,  -91377, 64947,  97385,  7217,   95272,  55539,
          99247,  -57615, -86504, -5115,  40623,  -17580, -71856, 31968,
          35735,  -85,    61625,  -36466, -53958, 96011,  -45321, -75848,
          75244,  77295,  -21182, 90396,  -12308, 1815,   12991,  40033,
          22669,  19397,  -10447, -89453, 75825,  21210,  29662,  -69789,
          33808,  -26623, -77239, -99375, 37335,  -98132, 77995,  -97224,
          -37233, 97439,  -70126, -10669, 40556,  -43699, -31128, 560,
          20094,  18984,  13755,  -60211, -48593, -71985, -69807, -77231,
          -84320, 3455,   -83145, -32494, 70963,  -66498, 86676,  -36892,
          63249,  -97669, -22156, -12362, 60808,  39997,  -71349, -45151,
          -54797, -4269,  96531,  98014,  95419,  -63225, -57991, 30180,
          -12071, 95223,  -55946, 88260,  -23263, 91545,  47317,  -62475,
          -95800, 34256,  -78436, 60597,  6648,   37704,  -74450, 25150,
          41976,  1412,   38554,  -17203, 2504,   48381,  -65252, -92935,
          -40622, -52301, -21791, 25129,  78553,  -34517, -49553, -35393,
          80773,  -54678, -35695, 55176,  70053,  27224,  84630,  -19634,
          -94600, -39556, -4630,  70285,  -16984, 93898,  -91845, -58867,
          15557,  -3424,  53178,  -41734, 87357,  -78289, -72122, 20614,
          -25181, 95737,  83133,  -79409, -76280, -51238, 6633,   76197,
          76031,  -61412, -39411, -45127, 98877,  -62696, 79358,  -38800,
          77254,  -31040, -85085, -6053,  -54520, -92270, -30045, -25454,
          -62893, -58762, 40000,  84926,  45035,  74857,  61113,  -49886,
          29593,  -98640, -1646,  0,      -74643, 42585,  13729,  21015,
          76563,  6102,   -39083, 86643,  -80581, -37033, 47747,  -54731,
          -44605, -76697, -95527, 19103,  11748,  -75615, -94342, 63459,
          -54594, -26070, 39824,  -14868, 973,    59603,  -53103, 7920,
          -96050, 35231,  -11520, -79797, -86100, -75480, -37467, -18742,
          -82997, -81324, -79050, -76066, 58780,  -20121, 41832,  -17426,
          -66451, 74542,  6249,   -47229, 66310,  15879,  -99017, -30030,
          92040,  -17277, -26350, 2971,   53229,  90318,  17746,  10299,
          -12770, 85621,  -29224, -49876, -31756, -23042, 47696,  -33229,
          -70936, 91560,  -43402, 18751,  -30060, 64503,  89551,  92801,
          -72795, 15080,  80418,  59274,  -40351, -59587, 83320,  19025,
          22012,  1783,   -45212, -75883, -75992, -18450, -34676, 19195,
          -48743, -75489, -64310, -61334, -37590, 60593,  -9447,  -90435,
          90960,  -71258, 51403,  -45648, -92693, -43859, -55090, -86800,
          92799,  43127,  20171,  57787,  34414,  -68375, 16641,  -80483,
          -44652, 1842,   14315,  15974,  81445,  -88627, 72220,  39911,
          9239,   -54946, -58695, 56929,  82253,  54189,  -84834, -95644,
          59304,  -40140, -54102, -94408, 1720,   -33884, 51580,  -1133,
          49352,  -73061, 78698,  -5099,  60811,  16616,  56891,  -51329,
          31728,  26671,  51661,  -22955, 3120,   -79760, 17158,  -547,
          69627,  -14650, -46289, 35563,  -70406, -92467, -98273, 7827,
          98795,  19531,  37442,  51516,  -14994, -21485, -33076, -57399,
          -72903, 68661,  67103,  -65676, 80108,  -55064, -97719, 17015,
          -56290, 63216,  1905,   75973,  67781,  -17280, -29209, -18831,
          -2135,  15827,  29536,  -83272, 57125,  20384,  80167,  89949,
          476,    -83954, 21576,  68666,  77467,  -39480, -72616, 41991,
          -74790, 33258,  -71789, -31256, -80482, -14282, 21934,  -33175,
          -19233, -41311, -50182, -26986, -88175, 2918,   58028,  33029,
          -21966, -93273, 51240,  33754,  -13460, -91604, -9065,  -96917,
          -51952, -53135, -12989, -84748, 53064,  77876,  -82763, -67325,
          -29755, -17290, -29585, 28192,  -75290, -45253, -36963, 1299,
          68447,  49715,  -58307, -40421, 67129,  95164,  33979,  53501,
          -4475,  10289,  74958,  14033,  -88200, 65089,  -12330, 35217,
          -19154, 21038,  9543,   -59662, 85936,  -96679, 97719,  36496,
          91247,  43788,  -71641, -74013, 45035,  65235,  83912,  85684,
          45989,  -16216, -36266, -77333, 519,    72615,  67045,  -34024,
          26661,  65825,  82819,  -28369, -77097, -27302, 36798,  -7361,
          14004,  9503,   -99321, 48765,  -92609, 4107,   -35076, 14365,
          -42879, 14454,  77106,  27450,  -48297, 30832,  -28968, 32141,
          61654,  -18023, 42217,  53900,  57289,  73465,  -15253, -96378,
          -10121, -40683, 1516,   64048,  82762,  21029,  -50961, -47292,
          -94097, 2657,   10761,  75752,  61466,  8621,   -55443, -93004,
          -73045, -33070, -78506, -54445, 92221,  -70688, -97707, -68573,
          42232,  -22556, -65209, -97802, 49152,  -55144, -26430, -35697,
          -72561, 12914,  35799,  -73234, 91835,  81921,  -53957, 22752,
          74086,  -10281, -60850, 68410,  -81377, -55331, -90395, 49943,
          -62689, 22431,  77992,  39816,  38699,  86971,  80639,  1370,
          25836,  -20109, 82857,  -5167,  83328,  18177,  -25590, -82317,
          -14824, 23489,  72091,  -29566, -15289, -73096, -8974,  -35109,
          -89210, 522,    59364,  6890,   24884,  16813,  41441,  7127,
          16179,  85784,  94537,  29870,  87561,  -67419, 74165,  45802,
          57732,  67332,  47854,  -40241, -90153, 72377,  40462,  79010,
          43819,  -1850,  -86623, 941,    43836,  -73280, -67701, 96112,
          34759,  -80044, 74390,  36152,  30048,  -4986,  59044,  14918,
          -59850, 50101,  41295,  -80179, -4269,  -55499, 28245,  54961,
          46057,  3510,   93928,  50805,  -37827, 82137,  9669,   -60904,
          -95497, -52579, 18675,  -21482, -75700, -23511, 40262,  32054,
          -31737, 58643,  -75111, -54750, 76735,  -30585, -68636, -47506,
          -49037, -32242, 85652,  -14908, 57316,  66714,  61420,  58060,
          -92550, -36632, -21259, -8153,  99196,  -95213, 2501,   88234,
          -6872,  -29429, 77448,  -12125, -82747, -58129, -30671, 62293,
          -66281, 73471,  38820,  25764,  -18921, 42630,  94410,  -11920,
          -33887, -36658, 98138,  -51618, 46044,  -1172,  98393,  -36425,
          -99020, 9000,   45596,  -94053, 67370,  -33913, 6543,   52733,
          -37148, -9739,  76824,  54400,  82380,  70778,  -28143, 73423,
          -40502, 67014,  -47155, -38338, -31491, 26610,  96849,  9218,
          -80710, 75055,  -14257, 18555,  -63615, -93466, -13725, -22679,
          -88849, 21226,  75251,  -5541,  -67217, 16714,  66437,  37879,
          7698,   14100,  83137,  -5715,  -54122, 18284,  -29658, 64915,
          -54040, -36933, 35140,  -89293, 43566,  20728,  -99438, -33637,
          -58031, -57110, 12623,  -77722, 17313,  -54239, 27010,  -65160,
          76978,  -54000, -92606, 34507,  87656,  66551,  61786,  93431,
          54544,  -19261, -91224, 7584,   -25748, 74108,  -24486, 91454,
          95019,  83028,  -33329, 92370,  56663,  -32053, -15976, -75457,
          16854,  6008,   14981,  80552,  86288,  68163,  8359,   -88981,
          -44621, 95356,  -80539, -91513, 8353,   43899,  85788,  94244,
          69880,  82466,  38283,  -34726, 236,    18909,  -1433,  -78166,
          -52061, -30316, 69651,  -10451, 9266,   47467,  -99890, -80411,
          -13673, -2227,  -74419, -10705, -92064, -62126, -54565, 58231,
          66972,  83028,  19798,  39070,  -25413, 66297,  69089,  2646,
          -70910, 58111,  66612,  57463,  -27888, 23781,  51951,  29230,
          3321,   -46787, -44872, 71950,  -71400, -11041, 49754,  -10008,
          -44806, -96670, -51368, 53559,  -41223, -32221, 18632,  -36728,
          -13617, -60919, -62847, 32622,  98521,  -2044,  -90182, -24409,
          66900,  -99804, -25880, 62704,  33599,  -92871, 27144,  -40825,
          40870,  -81584, -95401, 47080,  -25382, 64288,  -20548, -51872,
          52800,  -12338, 44840,  -20851, -13615, -33417, 24515,  -69341,
          14878,  -54041, 18561,  -31618, 28048,  -15946, -50560, 51381,
          -81230, 2028,   40251,  67544,  -94131, 17595,  -27531, 22710,
          8172,   -94077, 52125,  -43781, -1150,  -38569, 11243,  -52154,
          25869,  66670,  -58606, -5390,  -73608, 31064,  9524,   59361,
          -60481, -6380,  -18438, 71661,  3725,   -20566, -94051, -77910,
          37322,  -13740, -39907, 59928,  85122,  16381,  -73634, 66468,
          71023,  12722,  66639,  -36483, -91207, 69364,  59178,  -38044,
          56771,  88341,  51355,  60836,  68489,  79728,  -32880, -25098,
          10312,  -60384, -66653, -46054, -67149, 2672,   25811,  -53477,
          91736,  -17395, -70393, 80633,  87866,  91553,  41412,  97925,
          -85960, -40847, -65743, -78267, 88295,  88139,  -57749, 61258,
          -7306,  94160,  -48862, 49929,  19875,  -95402, 94292,  -74367,
          -85438, -56724, 93236,  90646,  83873,  29464,  -72516, 42192,
          -45881, 33842,  -672,   -21141, -99738, -55855, -94284, 27127,
          -7828,  8748,   44000,  74370,  -38602, 61292,  89545,  -91072,
          -87700, 92143,  -47808, 73563,  14783,  44272,  -30199, 84009,
          -53779, -85514, -75487, -84231, -67469, -54643, 45819,  -50514,
          46856,  39816,  64254,  9754,   49814,  62615,  66537,  62966,
          -52703, -41123, -74240, -22588, 80191,  -61769, 54174,  -87537,
          -85123, 80324,  -5216,  27833,  6750,   59527,  -55001, 77429,
          99609,  -87856, 55364,  72451,  -67188, -48021, 24134,  32407,
          93583,  67600,  -85741, 88310,  753,    15891,  79321,  -26775,
          65253,  -86071, -63904, 30553,  30661,  84858,  -72509, -77037,
          42920,  -59232, 81687,  -83474, -44528, -64781, -44359, 38204,
          82951,  -11908, -41555, 81370,  -50526, 41962,  96176,  -74683,
          25826,  58413,  -76656, -37429, -14021, 51035,  -31871, -42712,
          59848,  978,    5617,   -82277, -52162, -80492, -11071, 94926,
          -70032, -28194, -74801, 32255,  59829,  23276,  3488,   27896,
          2819,   61864,  -8863,  92416,  80318,  4491,   80683,  18398,
          91120,  19748,  -10039, 5651,   11018,  -24023, 79946,  18661,
          31478,  12228,  -74937, -74765, 71506,  91308,  78968,  55679,
          4119,   -92677, 49677,  -20608, 78953,  56978,  51853,  -10705,
          8271,   48475,  40204,  66962,  28032,  8819,   -16469, 34035,
          -90532, 52468,  -47390, 50234,  -32730, 6778,   6265,   69045,
          43279,  -10925, -24673, 12687,  -74637, -40963, 75766,  74534,
          -96917, -81325, 26184,  59555,  -55844, 17399,  63664,  -47907,
          57886,  20633,  -55076, -11953, -99806, 71330,  36767,  -74335,
          6910,   -68318, -43195, 96314,  79652,  76241,  73585,  -62409,
          -2194,  -35240, 17960,  -99088, 10403,  -36570, 1085,   -85800,
          -51415, 84467,  -69516, -96012, 55200,  -4314,  80100,  45495,
          28199,  61102,  -95572, 67183,  93917,  7136,   -12198, -25511,
          -43422, -60275, -79211, -53278, -39405, 40605,  -57681, -61309,
          -79279, -82226, -1486,  -30138, 75706,  -28717, 34626,  16419,
          23801,  94330,  -2356,  -47625, -76742, 1462,   3131,   -53264,
          60720,  -91692, 61024,  -13053, 80508,  88411,  -80603, 56000,
          -21686, 61896,  33999,  -4355,  92533,  14962,  -19461, -86246,
          58821,  -5714,  76536,  -99990, -85338, 78173,  14493,  6635,
          74988,  -15429, 6838,   -95179, 64891,  -1587,  -49440, -10043,
          44092,  -41257, -10225, -67232, 30413,  415,    -83364, 19891,
          -76653, -45631, -45168, -75866, -71072, 95143,  -59121, 10906,
          -60946, -74193, 32537,  35203,  -95579, 27447,  51034,  51949,
          19416,  67759,  -18062, 78550,  -64817, 52186,  81096,  59685,
          -29476, -2078,  -39637, -70819, 73012,  -66749, -27798, -64505,
          -38464, 33454,  2208,   -53020, -91969, -79170, -67905, 66714,
          13112,  -87864, -70063, 22009,  -84315, -57081, -15619, -30390,
          -92,    -88391, -561,   32867,  96119,  -88734, -25001, -55480,
          74515,  -57423, -40078, 97142,  -96020, 35881,  -73115, 10030,
          56325,  -87564, 46994,  43945,  -47398, 23233,  -71520, 63456,
          -7166,  -23483, 98881,  8781,   -66542, 62805,  74992,  74160,
          -51349, -83799, 8542,   53944,  -50365, -92445, 21872,  -42557,
          47322,  -62987, 78441,  -15219, -14221, -30482, 47160,  -38271,
          -35045, -40918, 29364,  3032,   -80687, -40805, -65672, -77496,
          -80145, -62289, -96119, -88390, -96,    92551,  77616,  96761,
          48864,  -54595, -67878, 65113,  -95057, -51364, 85118,  -47006,
          52188,  -46257, 17639,  -25498, -29657, -44930, 36219,  -51788,
          3317,   -90068, -72218, -25903, -52141, -52927, 35590,  -55181,
          44010,  80911,  -46985, 34978,  -71458, 96045,  -51730, 60562,
          3008,   -26017, 31099,  -59291, -61787, -81450, -57049, -45335,
          -96498, -48383, -85047, 35299,  -82084, 7584,   11869,  67442,
          -76497, -58485, -25671, 7257,   13382,  -9736,  9352,   -94846,
          32526,  16027,  78755,  -50741, -97048, 7386,   -32578, 59129,
          -56214, 95549,  41879,  -70802, -21110, -1397,  -85314, -67557,
          68827,  -6415,  198,    -11413, -29183, 34031,  73476,  -32539,
          31563,  50214,  6383,   86832,  29722,  25511,  32791,  -17129,
          6142,   64733,  -68447, 78030,  -77620, -21296, -35085, 98887,
          -62890, -33319, -88442, -51214, 11433,  4040,   -37341, 21936,
          -82438, -23062, 49754,  54526,  -66474, 29712,  -72405, -1379,
          81177,  -89659, 69158,  83054,  -93980, -22803, -35273, -67549,
          -40538, -89668, -77063, 804,    -53943, -45595, -99093, 99943,
          -5742,  -43461, -82657, 83697,  -77719, 32965,  81457,  -24395,
          -9883,  -31588, -14376, 90184,  -38541, 20299,  -57784, -85260,
          96851,  87846,  -7078,  76893,  38615,  58049,  -48639, -6351,
          17231,  -42204, 26123,  -49304, -12556, 95250,  96238,  -27569,
          -40641, 15935,  -78735, 77801,  18387,  -67563, 63948,  -84880,
          -84576, -76106, 42775,  27903,  34989,  16286,  90845,  -65857,
          -42743, -83668, 13261,  85578,  57104,  84202,  57031,  78220,
          -15314, -21370, 38643,  -37633, -94352, 3844,   -2683,  -70251,
          -29875, 41273,  -92137, -54584, -53320, -84652, 60979,  -49043,
          86814,  -47295, -27811, -66693, 94905,  -25473, -86386, -16285,
          79308,  98897,  69449,  97495,  -43971, -90974, -12134, 84398,
          -41015, 46662,  -22482, -1147,  -29421, -83797, 13383,  -89277,
          -69441, -46779, -78826, 79034,  -77325, -59298, -10564, -36721,
          42915,  94750,  -86987, 88850,  72492,  2948,   -15917, 82981,
          -74153, 43208,  -67294, 10178,  -57694, 58267,  -95886, -66090,
          84470,  27358,  -71383, 24946,  -77696, 77656,  49663,  33637,
          -50102, 91734,  48656,  68508,  53012,  -40887, -3720,  -23276,
          79104,  -15387, -47927, 39962,  -7021,  -35623, 48269,  -8853,
          -94369, 19753,  25633,  38739,  52520,  -48806, -22403, -10576,
          -63129, 84958,  -6680,  -11052, -71982, -62599, 20517,  -93608,
          12613,  -76420, -8644,  87940,  88594,  3868,   35670,  -17537,
          21649,  65134,  76425,  -60129, -8109,  85650,  81217,  -69990,
          42654,  16525,  -36099, 5494,   96392,  -1966,  -75030, 92546,
          -43813, -63879, -68435, -16411, -87029, 54865,  -28840, 12110,
          -59225, 28109,  -30306, -76677, -68466, 18474,  -65586, 55494,
          -59577, -53125, -26923, -78643, -74373, 5222,   -14426, -9828,
          98839,  -75961, 68183,  54417,  50530,  -66110, -17394, 94896,
          2012,   -14105, -68062, 17516,  5321,   -30316, -60773, -4422,
          -75540, -38028, -56513, -56365, 11581,  50526,  -60806, 62030,
          -48705, -30742, 33419,  -17788, -36557, -7688,  68706,  26628,
          26593,  63926,  -68774, -17274, -57267, 72981,  95296,  -70608,
          -81939, 59009,  21377,  96124,  50522,  -85760, 1052,   17815,
          -44820, -28708, 57151,  -93948, -5027,  24677,  30417,  -52374,
          -87535, -73739, -77261, -79151, -74993, 17719,  -47570, -89624,
          -62175, 93581,  -91673, 18659,  13497,  -98807, -41775, 64829,
          -1178,  51348,  32553,  60879,  -30532, 56227,  37424,  -23569,
          74277,  76406,  80500,  -78728, -68399, 53930,  30698,  -923,
          -85451, -72706, 77127,  -76348, 59,     19577,  54670,  38151,
          -92776, -2916,  5020,   75015,  -94781, -45823, -61305, -13105,
          25664,  85600,  95118,  -94883, 13723,  81617,  -56246, -432,
          38587,  -25425, 4913,   -61878, -95843, -89284, 40582,  60142,
          40962,  68008,  -1560,  -62695, 21170,  17406,  45201,  88719,
          -48380, 52962,  -69683, -42865, -68248, 60894,  -36765, 84610,
          -89169, -15637, 51851,  -96153, -44549, 41110,  45549,  89447,
          26234,  71748,  49223,  -31912, -13229, -39068, -91041, -12744,
          -24655, 74702,  59723,  -27111, -48181, -72506, 34886,  -62893,
          -82608, -47500, -15054, 85401,  -70635, 32744,  2756,   34474,
          97917,  35775,  83695,  -77134, -93136, -23509, -9209,  99940,
          -86244, 94059,  -80103, 78097,  -24691, -4437,  46022,  69085,
          -23101, -6481,  -28280, -92608, 50148,  -65947, 95776,  -37124,
          -23167, -66203, -4807,  -17097, 8008,   -75626, 86766,  -83697,
          36630,  67581,  -30814, 3725,   67669,  36425,  75158,  43185,
          52399,  -74579, -16886, 10260,  95056,  34872,  -89947, -96147,
          75775,  -45419, -10445, 16162,  45048,  -17255, 99452,  40470,
          -98369, 98400,  -47737, -70453, -1081,  77370,  -71799, 83959,
          98582,  -88421, -61004, 76029,  63501,  7656,   50930,  65581,
          66420,  96362,  -17849, -5955,  93170,  88454,  85157,  25093,
          48015,  -30192, 53861,  -86034, 91173,  -58122, -6914,  87030,
          13052,  48026,  74379,  69710,  -76568, 21951,  -34228, 43301,
          -69813, 18879,  -4392,  37537,  97036,  -3798,  18478,  -62877,
          44088,  -17426, 84509,  -76404, 15123,  68762,  78123,  37846,
          23879,  44155,  61674,  78722,  -48569, 68657,  4971,   96579,
          66194,  40527,  4656,   86036,  58216,  78347,  -93187, -63416,
          50257,  -84140, -48443, -97400, -98764, -68487, 27533,  26475,
          48910,  -63838, 53266,  3806,   45108,  67507,  62173,  87537,
          67896,  -49945, 23224,  64466,  45408,  66833,  -20439, 80557,
          43571,  -63424, 76114,  25914,  41289,  -84265, -8141,  12638,
          -91306, -11540, -47073, 68343,  -49158, -81545, -47879, -4289,
          -56420, -18388, -91191, -64310, -94517, 21545,  48438,  72434,
          80938,  -77236, 86481,  92840,  -95450, -99882, 41175,  93598,
          -21726, -19313, -1158,  -94412, -70180, -62218, -50195, -5266,
          -50780, 68046,  -62097, -65380, -61150, 66975,  35362,  -57658,
          47070,  2438,   69142,  8115,   -35265, -72823, -61266, -17733,
          39874,  57580,  17390,  80696,  63006,  25881,  16043,  -67728,
          21355,  -16362, 41975,  -39380, -52625, 1986,   18197,  89305,
          -59463, 72595,  14783,  -14505, 20176,  58883,  25082,  -173,
          -849,   42599,  15305,  8951,   -23623, -45994, -76210, -20405,
          18396,  -46339, -71769, -67275, -19394, -15621, -9530,  94024,
          21357,  -40878, -95947, 81473,  -24720, -85497, -64917, -84066,
          -17418, -40143, -20437, -1959,  -95363, -82171, -25313, -47214,
          19951,  56094,  11622,  -70370, -30370, 63154,  -68494, -36781,
          -25283, 96483,  -50861, 75913,  71692,  -9361,  96144,  20068,
          -81917, -93571, 11865,  79805,  33387,  -99060, -7713,  79197,
          -53321, 69568,  10363,  -21100, 17999,  51447,  -78499, 74488,
          -2795,  -9680,  -73756, -36428, 53076,  57430,  -30681, 58969,
          52988,  1629,   -63848, 11132,  -75442, 48607,  -48319, 24562,
          33216,  -95591, 69245,  -42452, -86315, -76292, 813,    -7133,
          -51895, 39614,  -50346, 16335,  98470,  -43837, -86021, -53042,
          80039,  -75941, -20055, -51477, 53748,  2744,   95177,  -33263,
          -72509, 79042,  -99502, 79777,  -87996, -65618, 25556,  175,
          83133,  -26790, 21292,  670,    -75730, -27047, 5353,   -50672,
          -29872, 35873,  -8918,  -6229,  -50700, -83595, 73455,  -92379,
          -74616, -71066, -4153,  58328,  12488,  -31215, 84308,  86158,
          32774,  -77077, -91739, 23872,  23924,  -6665,  96389,  -57144,
          13344,  -25002, 37747,  67895,  43967,  -12617, -25424, -84057,
          60836,  -69463, 92146,  -75638, -243,   -30058, 89596,  -77097,
          28381,  45281,  79294,  93788,  -76196, -8345,  90687,  -98017,
          -57783, -64435, -64707, 66256,  -70062, 21851,  -80513, -45810,
          -87320, -76168, -46474, 66429,  8707,   73414,  -42383, 19925,
          82638,  47526,  19545,  51357,  56125,  -57693, 93879,  33551,
          -38359, -48041, 43981,  -25535, -23675, -87506, 93893,  -96936,
          -85437, -4571,  -74499, 6872,   -23060, -21947, 14329,  72232,
          42280,  -641,   85474,  90040,  -21224, -94411, 87704,  50018,
          34968,  17486,  91266,  60662,  66374,  -82302, 39821,  88027,
          4415,   84227,  -70159, 48409,  50158,  -79065, -96235, -35239,
          37761,  92832,  30272,  -18781, 6194,   -51197, 65254,  -41869,
          516,    72304,  27683,  -12526, -84887, -17589, -44456, -54292,
          1759,   -36195, -25328, 23792,  21172,  90215,  -24771, -16487,
          77143,  -18520, 56509,  58305,  -50816, 65049,  -40489, -48791,
          -81617, 848,    -84215, -5693,  -29240, 31580,  32989,  72063,
          -60267, 28566,  38585,  -69800, -92415, -5558,  -78826, 71391,
          38663,  -5107,  23303,  -51802, 70363,  57761,  63991,  -29823,
          -28911, -99203, 89829,  -6288,  569,    -24140, -33469, 31465,
          -93289, -52487, -81904, -99950, 70804,  -98877, -19112, -76278,
          -56180, 75816,  -31635, -31623, -36628, 52612,  -49620, -55924,
          -92100, -2959,  -37382, -15525, -8081,  45943,  70763,  22781,
          -97942, -76418, -14533, -93848, -87449, 16461,  -94105, 21617,
          62429,  69627,  -23009, 92286,  45460,  -86544, 54992,  79001,
          43239,  -23589, 80384,  -48030, -16487, 82670,  98308,  83985,
          -13880, 39357,  -32755, -22703, 30879,  -51801, -40298, 29783,
          36167,  88419,  -4031,  40137,  89829,  67799,  54618,  -82782,
          -31195, -89185, -36163, -81685, -42871, -76976, -40085, -50034,
          47472,  -55504, -49840, -30222, 74279,  70371,  85324,  5445,
          60780,  -44423, -23442, 13954,  52115,  54608,  49621,  -55392,
          21945,  51852,  -63905, -15789, -20990, -99840, -56718, -39090,
          -1718,  -77890, 92301,  89860,  -40365, 18020,  12684,  -3994,
          -53395, -27292, 65777,  20624,  -59951, 56993,  -23456, -584,
          -8376,  -72919, 77061,  41985,  -44362, -75797, 47507,  56022,
          -52987, -4705,  -15149, 54183,  -14302, 17857,  -52200, 90356,
          21089,  21801,  -25501, 78010,  26674,  98295,  11528,  -20309,
          -35353, -97419, 13293,  -7480,  56168,  52415,  -22524, -31476,
          -86947, 94764,  -17513, -44205, -11481, -57307, 54806,  9505,
          -7769,  85378,  -58651, -48770, 4209,   83387,  14632,  90974,
          42984,  87270,  -85447, 12911,  59388,  43164,  -40062, 64688,
          80607,  52662,  21158,  -87184, 89175,  8977,   -30508, -14623,
          -77971, -7710,  -30140, -56249, 84027,  -73479, -8561,  -64260,
          -6636,  -4223,  -50864, 81005,  3011,   -88316, -59345, 32975,
          -6841,  -18461, 42649,  63899,  -57828, -78026, 91990,  -44534,
          16742,  26222,  -6979,  -16540, 69834,  79447,  81293,  -89583,
          -95899, 20365,  -41752, -79226, 82332,  -65612, 98765,  89258,
          59002,  5310,   -79281, -63690, -17563, 33992,  -49264, -9152,
          34008,  69750,  50933,  60319,  37,     -7368,  49694,  -44407,
          36010,  12811,  75905,  53458,  23207,  58553,  -24426, 84664,
          -8093,  73802,  -9186,  84869,  55439,  -20486, -18913, -91405,
          24448,  4067,   -72687, -28133, 96560,  -17747, 7670,   28883,
          -25044, 96368,  40226,  -46600, -54678, 95437,  -34801, -74429,
          -104,   -90583, 29341,  -15842, 70435,  78888,  72471,  77873,
          -29893, -8080,  56292,  -95807, 44552,  24189,  -46987, -65172,
          77603,  -43802, 20417,  43550,  61988,  66546,  1043,   -18635,
          99688,  36811,  -98234, 46443,  47638,  52004,  21167,  -99243,
          -11878, 13046,  -50669, -3297,  -25880, 74027,  -18536, 46951,
          38205,  8729,   97842,  88416,  -87812, -62850, 86685,  79302,
          60673,  78045,  -6603,  20115,  51252,  -5612,  10386,  -14472,
          -10283, -33378, -19277, 88326,  93196,  69661,  37079,  57884,
          -49158, -63110, -10403, 20628,  12311,  -93657, 55544,  7452,
          33925,  27238,  -71928, -1613,  -94543, -18485, 74327,  -40239,
          -59218, 92977,  -56856, 29228,  -68187, 48535,  13901,  95239,
          88723,  -89677, 38964,  -89009, 11458,  67959,  -84657, 53748,
          35527,  -94548, -44867, -55992, 25541,  -91879, 69899,  38469,
          -73270, 25381,  63576,  93213,  -50493, -62846, 84398,  -54531,
          52415,  -87320, -6353,  10827,  -4525,  -84212, 3186,   77864,
          12247,  -70294, 34038,  -17373, 20702,  59331,  24079,  -39243,
          21146,  -85273, -57560, -27262, -65559, -95158, -1498,  -4535,
          25369,  -61989, -36092, -56498, -58157, -4627,  -12920, -30164,
          -6998,  26564,  -34030, -18599, -94413, -45960, 29108 }
    };

    std::vector<int> expected_result{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i = 0; i < inputs.size (); i++)
        {
            std::cout << "INPUT ID : " << i << " of size " << inputs[i].size ()
                      << '\n';
            // Get the starting time
            auto start = std::chrono::high_resolution_clock::now ();

            int result = solution.threeSumClosest (inputs[i], 4);

            auto end = std::chrono::high_resolution_clock::now ();

            // Calculate the duration in milliseconds
            auto duration
                = std::chrono::duration_cast<std::chrono::milliseconds> (
                    end - start);

            std::cout << "Result is " << result << '\n';

            std::cout << "EXPECTED Result is \n";
            std::cout << expected_result[i];
            std::cout << '\n';
            // Print the duration
            std::cout << "Execution time: " << duration.count () << " ms"
                      << std::endl;
        }
    return 0;
}
