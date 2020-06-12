using System;
using System.Collections;
using System.Collections.Generic;

namespace Traffic_jam
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            var queue = new Queue<string>();
            string input = "";
            int counter = 0;
            while (input != "end")
            {
                input = Console.ReadLine();
                switch (input)
                {
                    case "green":
                        for (int i = 0; i < n; i++)
                        {
                            if (queue.Count > 0)
                            {
                                Console.WriteLine($"{queue.Dequeue()} passed!");
                                counter++;
                            }
                        }
                        break;
                    case "end":
                        Console.WriteLine($"{counter} cars passed the crossroads.");
                        break;
                    default:
                        queue.Enqueue(input);
                        break;
                }

            }
        }
    }
}
