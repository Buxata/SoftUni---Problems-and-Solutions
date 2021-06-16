using System;
using System.Collections.Generic;
using System.Linq;

namespace Sets_of_Elements
{
    class Program
    {
        static void Main(string[] args)
        {
            var Elements = new HashSet<string>();
            var Matching = new HashSet<string>();
            var input = Console.ReadLine().Split();
            int n =  int.Parse(input[0]);
            int m =  int.Parse(input[1]);
            for (int i = 0; i < n; i++)
            {
                Elements.Add(Console.ReadLine());
            }
            for (int i = 0; i < m; i++)
            {
                Matching.Add(Console.ReadLine());
            }

            Console.WriteLine(string.Join(" ", Elements.Intersect(Matching)));
        }
    }
}
