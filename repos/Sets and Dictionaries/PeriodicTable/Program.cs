using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;

namespace PeriodicTable
{
    class Program
    {
        static void Main(string[] args)
        {
            var elements = new HashSet<string>();
            var n = int.Parse(Console.ReadLine());
            for (int i = 0; i<n; i++)
            {
                var input = Console.ReadLine()
                    .Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);

                foreach (var element in input)
                {
                    elements.Add(element);
                }
            }
            Console.WriteLine(string.Join(" ", elements.OrderBy(x => x)));
        }
    }
}
