using System;
using System.Linq;

namespace Jagged_Array_Modification
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
                    square[r, c] = int.Parse(input[c]);
                }
            }

            while (input[0].ToLower() != "end")
            {
                input = Console.ReadLine().Split();
                if (input[0].ToLower() == "add")
                {
                    if(CoordinateCheck(int.Parse(input[1]), int.Parse(input[2]), matrix))
                    {
                        square[int.Parse(input[1]), int.Parse(input[2])] += int.Parse(input[3]);
                    }
                }
                else if (input[0].ToLower() == "subtract")
                {
                    if (CoordinateCheck(int.Parse(input[1]), int.Parse(input[2]), matrix))
                    {
                        square[int.Parse(input[1]), int.Parse(input[2])] -= int.Parse(input[3]);
                    }
                }
                else if (input[0].ToLower() == "end")
                {
                    for (int r = 0; r < matrix; r++)
                    {
                        for (int c = 0; c < matrix; c++)
                        {
                            Console.Write($"{square[r, c]} ");
                        }
                        Console.WriteLine();
                    }
                    break;

                }
            }
        }
        static bool CoordinateCheck(int row, int col, int max)
        {
            if (( row < max ) && ( row >= 0 ) && ( col < max ) && ( col >= 0 ))
            {
                return true;
            }
            else
            {
                Console.WriteLine("Invalid coordinates");
                return false;
            }
        }
    }
}
