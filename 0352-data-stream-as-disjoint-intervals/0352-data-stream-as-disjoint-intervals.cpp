class SummaryRanges {
public:
   std::vector<std::vector<int>> intervals;

   SummaryRanges()
   {

   }

   void addNum(int value)
   {
      if (intervals.size() == 0)
      {
         intervals.push_back({ value, value });
         return;
      }

      int i = 0;
      while (i < intervals.size())
      {
         if (intervals[i].front() >= value)
         {
            break;
         }

         ++i;
      }

      if (i < intervals.size())
      {
         if (value + 1 < intervals[i].front())
         {
            intervals.insert(intervals.begin() + i, { value, value });
         }
         else
         {
            intervals[i].front() = std::min(intervals[i].front(), value);

         }

         if (i > 0 && intervals[i].front() <= intervals[i - 1].back() + 1)
         {
            intervals[i - 1].back() = std::max(intervals[i].back(), intervals[i - 1].back());
            intervals.erase(intervals.begin() + i);
         }
      }
      else
      {
         intervals.push_back({ value, value });
         if (intervals[i - 1].back() + 1 >= intervals[i].front())
         {
            intervals[i - 1].back() = std::max(value, intervals[i - 1].back());
            intervals.erase(intervals.begin() + i);
         }
      }
      return;

   }

   std::vector<std::vector<int>> getIntervals() {

      return intervals;
   }

};
/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */