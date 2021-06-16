using System;
using System.Linq;
using System.Collections.Generic;

namespace CountSymbols
{
    class Program
    {
        static void Main(string[] args)
        {
            var input = Console.ReadLine();
            var symbols = new Dictionary<char, int>();

            foreach(char symbol in input)
            {
                if (!symbols.ContainsKey(symbol)) symbols[symbol] = 0;
                symbols[symbol]++;
            }

            Console.WriteLine(string.Join(Environment.NewLine, symbols
                .OrderBy(sym => sym.Key).Select(sym => $"{sym.Key}: {sym.Value} time/s")));

        }
    }
}
