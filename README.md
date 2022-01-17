# Thicc Menu
A very simple, header only c++ based menu library
#### Note: currently windows only, as it uses the winapi for the cursor. Linux compability will follow soon.
### Basic Example
```cpp
#include "thiccmenu.hpp"

int main() {
	switch (thiccmenu::Menu({"1. Say hi", "2. Say bye"}, Colors::Gray, Colors::Darkgray)) {
	case 1:
		std::cout << "hi\n";
		break;
	case 2:
		std::cout << "bye\n";
		break;
	}
}
```

### Showcase

https://user-images.githubusercontent.com/57799248/149838460-e0f7f975-8419-47c8-834d-3bb46f8a6103.mp4

