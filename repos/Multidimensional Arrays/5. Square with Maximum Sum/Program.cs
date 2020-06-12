using System;
using System.Collections.Generic;
using System.Globalization;

namespace Square_with_Minimum_Sum
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            int rows = int.Parse(input[0].Trim(','));
            int cols = int.Parse(input[1].Trim(','));
            int[,] matrix = new int[rows,cols];


            for (int i = 0; i < rows; i++)
            {
                input = Console.ReadLine().Split();
                for (int n = 0; n < cols; n++)
                {
                    matrix[i, n] = int.Parse(input[n].Trim(','));
                }
            }
            int a1,a2,b1,b2;
            int sumtbt;
            int[,] twobytwo = {{0, 0},{0, 0}};
            for (int i = 0; i < ( rows - 1 ); i++)
            {
                for (int n = 0; n < (cols-1); n++)
                {
                    a1 = matrix[i, n];
                    a2 = matrix[i, n+1];
                    b1 = matrix[i+1, n];
                    b2 = matrix[i+1, n+1];
                    int sum = a1+a2+b1+b2;
                    sumtbt = twobytwo[0,0]+twobytwo[1,0]+twobytwo[0,1]+twobytwo[1,1];
                    if (sum > sumtbt)
                    {
                        twobytwo[0, 0] = a1;
                        twobytwo[0, 1] = a2;
                        twobytwo[1, 0] = b1;
                        twobytwo[1, 1] = b2;
                    }
                }
            }
            sumtbt = twobytwo[0, 0] + twobytwo[1, 0] + twobytwo[0, 1] + twobytwo[1, 1];
            Console.WriteLine($"{twobytwo[0, 0]} {twobytwo[0, 1]}\n{twobytwo[1, 0]} {twobytwo[1, 1]}\n{sumtbt}");
        }
    }
}
