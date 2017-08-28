# Lecture 4

## Appendix A.4: Selection Structures

### `if` Statements

An `if` statement can be used to create alternative pathways of execution, depending upon some _condition_. For example, 

```c++
int age;
bool legalAge{false};
std::cin >> age;

if (age > 20) {
    legalAge = true;
}
```

In the above code, whenever the expression `age > 20` evaluates to true, the variable `legalAge` is set to true. In all other cases, `legalAge` retains its initial value of `false`.

By the way, the above code can be dramatically simplified by recognizing that boolean expressions evaluate to a boolean value:

```c++
int age;
bool legalAge;

std::cin >> age;
legalAge = (age > 20);
```

Notice we didn't use a conditional in this case. However, when it comes to testing, we still should test both possible cases, i.e, cases where `age > 20` is true, and cases where `age > 20` is false.

### `if else` Statements

The `if else` statement is another way of providing two alternative pathways of execution. You can think of them as mutually exclusive paths of execution. With the `if`, we either follow an alternative path, or we don't. With the `if else` we either follow one path _**or**_ we follow a different path. For example:

```c++
int age;
bool legalAge;

std::cin >> age;
legalAge = (age > 20);

std::cout << "See you at the ";
if (legalAge) {
    std::cout << "bar";
} else {
    std::cout << "library";
}
std::cout << "!\n";
```

For more details, see [http://en.cppreference.com/w/cpp/language/if](http://en.cppreference.com/w/cpp/language/if)

### `switch` Statements

With the `if`-flavor statements, we're choosing between _two_ alternative paths of execution. Using the `switch` statement, we can provide _multiple_ paths of execution. For example:

```c++
enum WEEKDAY {MON, TUE, WED, THU, FRI};
WEEKDAY day = FRI;
std::string mood;
switch(day) {
    case MON:
        mood = "awful";
        break;
    case TUE:
        mood = "ok";
        break;
    case WED:
        mood = "hump";
        break;
    case THU:
        mood = "better";
        break;
    case FRI:
        mood = "yea ha";
        break;
    }
```

For greater context, see the code in [src/main/cpp/Demo.cpp](../src/main/cpp/Demo.cpp) which is an adaptation of the code found [here](http://www.cplusplus.com/reference/locale/time_get/get_weekday/).

For more details, see [http://en.cppreference.com/w/cpp/language/switch](http://en.cppreference.com/w/cpp/language/switch)
