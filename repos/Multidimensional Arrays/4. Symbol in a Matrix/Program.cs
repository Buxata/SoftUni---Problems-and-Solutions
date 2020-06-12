using System;

namespace Symbol_in_a_Matrix
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            int matrix = int.Parse(input);
            char [,] square = new char [matrix, matrix];
            bool inSquare = false;

            for (int c = 0; c < matrix; c++)
            {
                input = Console.ReadLine();
                for (int r = 0; r < matrix; r++)
                {
                    square[c, r] = input[r];
                }
            }
            input = Console.ReadLine();
            for (int c = 0; c < matrix; c++)
            {
                for (int r = 0; r < matrix; r++)
                {
                    if (input[0] == square[c, r])
                    {
                        Console.WriteLine($"({c}, {r})");
                        inSquare = true;
                        break;
                    }
                    

                }
                if (inSquare) break;
            }
            if (!inSquare) Console.WriteLine($"{input[0]} does not occur in the matrix");
        }
    }
}
