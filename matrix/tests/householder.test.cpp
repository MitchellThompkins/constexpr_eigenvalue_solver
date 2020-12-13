#include <gtest/gtest.h>
#include "test_tools.hpp"

#include "decompositions.hpp"

using namespace consteig;

TEST(householder, house)
{
    static constexpr int s {10};
    static constexpr Matrix<float,s,s> mat
    {{{
    {-2.0114, -0.52132, -0.28604, 2.2908, -0.52351, 2.4257, -0.59398, 0.027539, 0.2731, 0.60314},
    {-0.42729, -0.47479, -0.28187, -0.6335, -0.84281, -0.88644, -0.77489, -0.36081, 0.76563, 0.28955},
    {1.0231, 0.76388, 0.37392, -1.5837, 0.22278, -1.9364, 0.54418, 0.19389, -0.6478, 1.1075},
    {0.34136, 1.764, -1.1581, 1.0057, 0.312, 0.87686, 0.31207, -0.45453, -1.3822, -0.72451},
    {1.6328, -1.7138, -0.4628, 0.76678, -0.85746, -1.0017, -1.0454, 0.31179, -0.71718, -0.19216},
    {0.59688, -0.4885, 1.3867, 1.8407, 0.076099, 0.33187, -0.86447, -0.2873, -0.50884, -1.1118},
    {0.46716, -0.62785, 0.6553, 0.8872, -0.9114, 0.91303, 0.45458, -0.43831, -0.45411, -1.1096},
    {0.54705, 1.7937, -0.7893, -0.11453, -1.3022, -0.4695, -0.48678, -0.23694, -0.4487, 0.35993},
    {0.13375, 1.4146, 0.03702, 0.29992, -0.27342, -1.1086, 0.6296, -1.4377, 1.4777, -3.0378},
    {0.81169, 0.3244, 2.2287, -0.72454, -1.6842, -1.5909, -1.0693, 0.72293, -1.4584, 0.68517},
    }}};

    static constexpr Matrix<float,s,s> test{house(mat)};

    static constexpr Matrix<float,s,s> answer
    {{{
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -0.18117, 0.43379, 0.14474, 0.69232, 0.25308, 0.19807, 0.23195, 0.056709, 0.34416},
    {0, 0.43379, 0.84069, -0.053156, -0.25426, -0.092943, -0.072743, -0.085184, -0.020826, -0.12639},
    {0, 0.14474, -0.053156, 0.98226, -0.084836, -0.031012, -0.024272, -0.028423, -0.006949, -0.042172},
    {0, 0.69232, -0.25426, -0.084836, 0.5942, -0.14834, -0.1161, -0.13595, -0.033239, -0.20172},
    {0, 0.25308, -0.092943, -0.031012, -0.14834, 0.94578, -0.04244, -0.049698, -0.01215, -0.073739},
    {0, 0.19807, -0.072743, -0.024272, -0.1161, -0.04244, 0.96678, -0.038896, -0.0095097, -0.057713},
    {0, 0.23195, -0.085184, -0.028423, -0.13595, -0.049698, -0.038896, 0.95445, -0.011136, -0.067583},
    {0, 0.056709, -0.020826, -0.006949, -0.033239, -0.01215, -0.0095097, -0.011136, 0.99728, -0.016523},
    {0, 0.34416, -0.12639, -0.042172, -0.20172, -0.073739, -0.057713, -0.067583, -0.016523, 0.89972},
    }}};

    static constexpr float thresh {1e-4F};
    static_assert(compareFloatMat(test, answer, thresh), MSG);
    ASSERT_TRUE(compareFloatMat(test, answer, thresh));
}

TEST(householder, house_single)
{
    static constexpr int s {2};
    static constexpr Matrix<float,s,s> mat
    {{{
    {-2.0114, -0.52132},
    {-0.42729, -0.47479},
    }}};

    static constexpr Matrix<float,s,s> test{house(mat)};

    static constexpr Matrix<float,s,s> answer
    {{{
    {1.0, 0.0},
    {0.0, -1.0},
    }}};

    static constexpr float thresh {1e-4F};
    static_assert(compareFloatMat(test, answer, thresh), MSG);
    ASSERT_TRUE(compareFloatMat(test, answer, thresh));
}
