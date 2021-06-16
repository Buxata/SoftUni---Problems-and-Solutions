using System;
using System.Collections.Generic;

namespace Wardrobe
{
    class Program
    {
        static void Main(string[] args)
        {
            var n = int.Parse(Console.ReadLine());
            var Colors = new Dictionary<string, Dictionary<string,int>>();

            for (int i = 0; i < n; i++)
            {
                var input = Console.ReadLine().Split(" -> ");
                string color = input[0];
                var clothes = input[1].Split(",");

                if (!Colors.ContainsKey(color))
                {
                    Colors.Add(color, new Dictionary<string, int>());
                }
                foreach (string cloth in clothes)
                {
                    if (!Colors[color].ContainsKey(cloth))
                    {
                        Colors[color].Add(cloth, 0);
                    }
                    Colors[color][cloth]++;
                }
            }
            var lookup = Console.ReadLine().Split(" ");
            string cNeed = lookup[0];
            string iNeed = lookup[1];

            foreach(var col in Colors)
            {
                Console.WriteLine($"{col.Key} clothes:");
                var clothesLine = col.Value;

                foreach(var clo in clothesLine)
                {
                    string output = $"* {clo.Key} - {clo.Value}";
                    if (cNeed == col.Key && iNeed == clo.Key)
                     {
                        output += " (found!)";
                     }

                     Console.WriteLine(output);
                }
            }
        }
    }
}
