using System;
using System.Collections.Generic;
using System.IO;

namespace Supermarket
{
    class Program
    {
        static void Main(string[] args)
        {
            var people = new Queue<string>();
            string input ="";
            while (input.ToLower() != "end")
            {
                input = Console.ReadLine();
                switch (input.ToLower())
                {
                    case "paid":
                        while(people.Count!=0)
                        {
                            Console.WriteLine(people.Dequeue());
                        }
                        break;
                    case "end":
                        Console.WriteLine($"{people.Count} people remaining.");
                        break;
                    default:
                        people.Enqueue(input);
                        break;
                }

            }
        }
    }

}