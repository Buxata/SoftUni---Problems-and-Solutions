using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;

namespace V_Logger
{
    class Program
    {
        static void Main(string[] args)
        {
            var database = new Dictionary<string, Dictionary<string, SortedSet<string>>>();
            bool running = true;

            while (running)
            {
                var input = Console.ReadLine().Split(" ");
                string command = input[1];
                string vloger = input[0];

                if (input[0]!="Statistics")
                switch (command)
                {
                    case "joined":
                        if (!database.ContainsKey(vloger))
                        {
                            database.Add(vloger, new Dictionary<string, SortedSet<string>>());
                            database[vloger].Add("following", new SortedSet<string>());
                            database[vloger].Add("followedBy", new SortedSet<string>());
                        }
                        break;
                    case "followed":
                        string member = input[2];
                        if (vloger != member && 
                            database.ContainsKey(vloger) &&
                            database.ContainsKey(member))
                            {
                            database[member]["followedBy"].Add(vloger);
                            database[vloger]["following"].Add(member);
                            }
                        break;
                    default:
                        Console.WriteLine("Not a valid command");
                        break;
                }
                else
                {
                    Console.WriteLine($"The V-Logger has a total of {database.Count} vloggers in its logs.");

                    int number =1;

                    foreach (var member in database.OrderByDescending
                        (v => v.Value["followers"].Count).ThenBy(v => v.Value["following"].Count))
                    {
                        Console.WriteLine($"{number}. {vloger.Key} : {vloger.Value["followers"].Count} followers, {vloger.Value["following"].Count} following");
                    }


                }
            }
        }
    }
}