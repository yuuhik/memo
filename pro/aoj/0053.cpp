#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> prime(int maxN);

int main(int argc, char *argv[])
{
  int n;

  while (std::cin >> n, n!=0) {
    std::vector<int> v = prime(n);
    int ans = 0;
    
    for (int i = 0; i < v.size(); ++i) {
      ans += v[i];
    }
    std::cout << ans << std::endl;
  }
  return 0;
}

// under 500000
std::vector<int> prime(int maxN) {
  int n = 500000;
  std::vector<bool> vec(n+1);

  for (int i = 0; i <= vec.size(); ++i) { vec[i] = true; }
  vec[0] = false;
  vec[1] = false;

  int n_sqrt = (int)(sqrt(n));
  
  // from 2
  for (int i = 2; i < n_sqrt+1; ++i) {
    // if number is false then
    if (!vec[i]) { continue; }
      
    // i * 2 : to self number avoid
    for (int j = i * 2; j <= n; j += i) {
      if (vec[j]) {
	vec[j] = false;
      }
    }
  }

  std::vector<int> result;

  for (int i = 0,
	 count = 0;
       count < maxN; ++i) {
    if (vec[i])
      {
	++count;
	result.push_back(i);
      }
  }

  return result;
}
