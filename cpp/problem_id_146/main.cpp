#include <algorithm>
#include <deque>
#include <list>
#include <unordered_map>

// Shitty but works
/*
class LRUCache
{
 private:
   // for keeping track of the LRU
   std::deque<int> queue;
   // for O(1) access
   std::unordered_map<int, int> map;

 private:
   int capacity;

 public:
   LRUCache (int capacity) { this->capacity = capacity; }

   int
   get (int key)
   {
      if (map.count (key))
         {
            auto it = std::find (queue.begin (), queue.end (), key);
            queue.erase (it);
            queue.push_back (key);
            return map[key];
         }
      else
         return -1;
   }

   void
   put (int key, int value)
   {
      if (map.count (key))
         {
            map[key] = value;
            auto it = std::find (queue.begin (), queue.end (), key);
            queue.erase (it);
            queue.push_back (key);
         }
      else if (map.size () >= capacity)
         {
            int key_LRU = queue.front ();
            queue.pop_front ();
            map.erase (key_LRU);
            map[key] = value;
            queue.push_back (key);
         }
      else
         {
            map[key] = value;
            queue.push_back (key);
         }
   }
};
*/

class LRUCache
{
 private:
   // for keeping track of the LRU
   std::list<int> queue;
   std::unordered_map<int, std::list<int>::iterator> queue_map;
   // for O(1) access
   std::unordered_map<int, int> map;

 private:
   int capacity;

 public:
   LRUCache (int capacity) { this->capacity = capacity; }

   int
   get (int key)
   {
      if (map.count (key))
         {
            // Move key to the back (MRU side)
            auto it = queue_map[key];
            queue.erase (it);
            queue.push_back (key);
            queue_map[key] = std::prev (queue.end ());
            return map[key];
         }
      return -1;
   }

   void
   put (int key, int value)
   {
      if (map.count (key))
         {
            map[key] = value;
            auto it = queue_map[key];
            queue.erase (it);
            queue.push_back (key);
            queue_map[key] = std::prev (queue.end ());
         }
      else
         {
            if (map.size () >= capacity)
               {
                  int key_LRU = queue.front ();
                  queue.pop_front ();
                  map.erase (key_LRU);
                  queue_map.erase (key_LRU);
               }
            map[key] = value;
            queue.push_back (key);
            queue_map[key] = std::prev (queue.end ());
         }
   }
};
