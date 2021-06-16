using System;

namespace FizzBuzz
{
    class Program
    {
        static void Main(string[] args)
        {
            int iteration = int.Parse(Console.ReadLine());

            for (int i = 1; i <= iteration; i++)
            {
                string output = "";
                if (i % 3 == 0) output += "Fizz";
                if (i % 5 == 0) output += "Buzz";

                if (output == "") output = $"{i}";

                Console.WriteLine(output);
            }
        }
    }
}
