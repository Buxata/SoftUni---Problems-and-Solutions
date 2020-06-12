using System;

namespace Primary_Diagonal
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine().Split();
            int matrix = int.Parse(input[0]);
            int [,] square = new int [matrix, matrix];


            for (int r = 0; r < matrix; r++)
            {
                input = Console.ReadLine().Split();
                for (int c = 0; c < matrix; c++)
                {
                    
                    square[r,c] = int.Parse(input[c]);
                }
            }
            int temp = 0;

            for (int r = 0; r < matrix; r++)
            {
                for (int c = 0; c < matrix; c++)
                {
                    if (r == c) temp += square[r, c];
                }
            }
            Console.WriteLine(temp);
        }
    }
}
