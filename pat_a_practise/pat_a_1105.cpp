#if 0
题目大意：
    fill a sequence of N positive integers into a spiral matrix in non-increasing order
    即顺时针由外向内按降序填充矩阵，左上角为起始点
输入：
    首行：总的节点数N
    次行：N个数字值k，空格隔开
        --N，k <= 10^4
输出：
    m行：n个数字，格式同输入
        -- st. N = m * n
.
#endif

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>

int32_t _calc_row_num_(int32_t N)
{
    auto sq_n = (int32_t)floor(sqrt(N));
    while (N % sq_n && --sq_n);
    return N / sq_n;
}

bool _cmp(int32_t a, int32_t b)
{
    return a > b;
}

int main ()
{
    int32_t N = 0;
    scanf("%d", &N);
    int32_t row = _calc_row_num_(N), col = N / row;
    int32_t matrix[row][col] = {0};
    memset(matrix, -1, sizeof(matrix));
    int32_t sequence[N] = {0};
    for (int32_t idx = 0; idx != N; ++idx)
    {
        std::cin >> sequence[idx];
    }
    std::sort(sequence, sequence+N, _cmp);
    int32_t index = 0;
#ifdef __FUNC_1__
    /* 游标法 */
    int32_t cur_col = 0, cur_row = 0, dirc=0;
    while (index < N)
    {
        switch (dirc % 4)
        {
            case 0:
                {
                    while (cur_col < col && matrix[cur_row][cur_col] == -1)
                    {
                        matrix[cur_row][cur_col++] = sequence[index++];
                    }
                    ++cur_row; --cur_col;
                }
                break;
            case 1:
                {
                    while (cur_row < row && matrix[cur_row][cur_col] == -1)
                    {
                        matrix[cur_row++][cur_col]= sequence[index++];
                    }
                    --cur_row; --cur_col;
                }
                break;
            case 2:
                {
                    while (cur_col >= 0 && matrix[cur_row][cur_col] == -1)
                    {
                        matrix[cur_row][cur_col--]= sequence[index++];
                    }
                    --cur_row; ++cur_col;
                }
                break;
            case 3:
                {
                    while (cur_row >= 0 && matrix[cur_row][cur_col] == -1)
                    {
                        matrix[cur_row--][cur_col]= sequence[index++];
                    }
                    ++cur_row; ++cur_col;
                }
                break;
            default:
                break;
        }
        ++dirc;
    }
#else
    /* 层级法 */
    int layers = int(ceil(row / 2.0));
    for (int32_t _layer = 0; _layer != layers; ++_layer)
    {
        for (int i = _layer; i < col-_layer && index < N; ++i)
        {
            matrix[_layer][i] = sequence[index++];
        }
        for (int i = _layer+1; i < row-_layer && index < N; ++i)
        {
            matrix[i][col-1-_layer] = sequence[index++];
        }
        for (int i = col-1-(_layer+1); i >= 0 + _layer && index < N; --i)
        {
            matrix[row-1-_layer][i] = sequence[index++];
        }
        for (int i = row-1-(_layer+1); i >= 0 + (_layer+1) && index < N; --i)
        {
            matrix[i][_layer] = sequence[index++];
        }
        if (index >= N)
        {
            break;
        }
    }
#endif
    for (int32_t _row = 0; _row != row; ++_row)
    {
        for (int32_t _col = 0; _col != col; ++_col)
        {
            printf("%d", matrix[_row][_col]);
            if (_col+1 < col)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
