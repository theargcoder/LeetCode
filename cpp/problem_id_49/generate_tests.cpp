
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string
generate_random_string (int length)
{
   const std::string letters = "abcdefghijklmnopqrstuvwxyz";
   std::string random_string;
   for (int i = 0; i < length; ++i)
      {
         random_string += letters[rand () % letters.length ()];
      }
   return random_string;
}

std::vector<std::string>
generate_random_input (int num_strings, int max_length)
{
   std::vector<std::string> strs;
   for (int i = 0; i < num_strings; ++i)
      {
         int length
             = rand ()
               % (max_length + 1); // Random length between 0 and max_length
         strs.push_back (generate_random_string (length));
      }
   return strs;
}

std::string
to_json_format (const std::vector<std::string> &strs)
{
   std::ostringstream oss;
   oss << "[\n";
   for (size_t i = 0; i < strs.size (); ++i)
      {
         oss << "\"" << strs[i] << "\"";
         if (i < strs.size () - 1)
            {
               oss << ",";
            }
         oss << "\n";
      }
   oss << "]\n";
   return oss.str ();
}

int
main ()
{
   srand (static_cast<unsigned int> (time (0))); // Seed for randomness

   const int min_num_strings = 1;
   const int max_num_strings = 100;
   const int max_str_length = 100;

   // Generate a random number of strings (between 1 and 10,000)
   int num_strings
       = rand () % (max_num_strings - min_num_strings + 1) + min_num_strings;

   // Generate the random strings based on the random number of strings
   std::vector<std::string> random_strings
       = generate_random_input (num_strings, max_str_length);

   // Convert the result to JSON format and output it
   std::string json_output = to_json_format (random_strings);
   std::cout << json_output << std::endl;

   return 0;
}
