#include <bitset>
#include <vector>

typedef std::bitset<9> state;

state solve(state input)
{
  state result;
  std::vector<int> buttonsToPress;

  // Iterate over all possible button presses
  for (int i = 0; i < 512; ++i)
  {
    state current = input;

    // Press the buttons according to the current combination
    for (int j = 0; j < 9; ++j)
    {
      if ((i >> j) & 1)
      {
        current.flip(j);
        if (j - 3 >= 0)
          current.flip(j - 3);
        if (j + 3 < 9)
          current.flip(j + 3);
        if (j % 3 != 0)
          current.flip(j - 1);
        if (j % 3 != 2)
          current.flip(j + 1);
      }
    }

    // Check if all the lights are turned on
    if (current.all())
    {
      result = state(i);
      break;
    }
  }

  return result;
}