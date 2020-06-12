using System;
using System.Collections.Immutable;

namespace Sum_Matrix_Elements
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            int rows = int.Parse(input[0].Trim(','));
            int cols = int.Parse(input[1].Trim(','));
            int[,] matrix = new int[rows,cols];

            for (int i =0; i<rows; i++)
            {
                input = Console.ReadLine().Split();
                for(int n = 0; n<cols; n++)                      
                {
                    matrix[i, n] = int.Parse(input[n].Trim(','));
                }
            }
            int temp=0;
            foreach (int num in matrix)
            {
                temp += num;
            }
            Console.WriteLine($"{rows}\n{cols}\n{temp}");

        }
    }
}
