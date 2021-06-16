using System;
using System.Collections.Generic;

namespace EvenTimes
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var numbers = new Dictionary<string, int>();

            for (int i = 0; i < n; i++)
            {
                var input = Console.ReadLine();
                // check if there is and entry inf dictionary.
                // if there is an entry add +1 to key
                // if there isn't and entry add the input to the dictionary with a key => 1
                if (!numbers.ContainsKey(input))
                {
                    numbers[input] = 0;
                }
                numbers[input]++;
            }
    
            foreach(var number in numbers)
            {
                if (number.Value % 2 == 0) Console.WriteLine(number.Key);
            }
        }
    }
}
