#include <cstdint>
#include <string>
#include <string_view>
#include <vector>

struct row
{
  uint8_t A : 1, B : 1, C : 1, D : 1, A_was_3 : 1, D_was_3 : 1;
};

class BusBooking
{
private:
  uint32_t total_sum = 0;
  uint32_t total_booked = 0;
  std::vector<row> bus;

public:
  BusBooking(const int n) : bus(n + 2, row{ .A = 0, .B = 0, .C = 0, .D = 0, .A_was_3 = 0, .D_was_3 = 0 }) {};

  void toggle(const std::string &seat)
  {
    const auto chair = seat[0];
    const auto row_num = std::stoi(&seat[1]);

    switch(chair)
    {
    case 'A':
    {
      if(bus[row_num].A)
      {
        total_booked--;
        total_sum--;

        if(bus[row_num].A_was_3)
          total_sum -= 2;

        bus[row_num].A = 0;
        bus[row_num].A_was_3 = 0;
      }
      else
      {
        total_booked++;
        total_sum++;

        bus[row_num].A_was_3 = bus[row_num].B;

        if(bus[row_num].A_was_3)
          total_sum += 2;

        bus[row_num].A = 1;
      }
    }
    break;
    case 'B':
    {
      total_booked += (bus[row_num].B) ? -1 : +1;
      total_sum += (bus[row_num].B) ? -1 : +1;
      bus[row_num].B = ~bus[row_num].B;
    }
    break;
    case 'C':
    {
      total_booked += (bus[row_num].C) ? -1 : +1;
      total_sum += (bus[row_num].C) ? -1 : +1;
      bus[row_num].C = ~bus[row_num].C;
    }
    break;
    case 'D':
      if(bus[row_num].D)
      {
        total_booked--;
        total_sum--;

        if(bus[row_num].D_was_3)
          total_sum -= 2;

        bus[row_num].D = 0;
        bus[row_num].D_was_3 = 0;
      }
      else
      {
        total_booked++;
        total_sum++;

        bus[row_num].D_was_3 = bus[row_num].C;

        if(bus[row_num].D_was_3)
          total_sum += 2;

        bus[row_num].D = 1;
      }
      break;
    }
  }

  int getTotalTime()
  {
    return total_sum;
  }

  int getMinTime()
  {
    return total_booked;
  }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */

//

int main(int argc, char *argv[])
{
  BusBooking bus(1);

  bus.toggle("B1");
  bus.toggle("A1");
  const auto res_1 = bus.getTotalTime();
  bus.toggle("D1");
  const auto res_2 = bus.getTotalTime();
  bus.toggle("B1");
  const auto res_3 = bus.getTotalTime();
  bus.toggle("A1");
  bus.toggle("A1");
  bus.toggle("D1");
  const auto res_4 = bus.getMinTime();
  const auto res_5 = bus.getMinTime();
  bus.toggle("A1");
  const auto res_6 = bus.getTotalTime();

  return 0;
}
