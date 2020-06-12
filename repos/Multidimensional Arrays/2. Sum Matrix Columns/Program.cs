using System;

namespace Sum_Matrix_Columns
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            int rows = int.Parse(input[0].Trim(','));
            int cols = int.Parse(input[1]);
            int [,] matrix = new int[rows,cols];

            for (int r = 0; r < rows; r++)
            {
                input = Console.ReadLine().Split();
                for (int c = 0; c < cols; c++)
                {
                    matrix[r, c] = int.Parse(input[c]);
                }
            }

            for (int c = 0; c<cols; c++)
            {
                int tempCol = 0;

                for (int r = 0; r < rows; r++)
                {
                    tempCol += matrix[r, c];
                }
                Console.WriteLine(tempCol);
            }

        }
    }
}
