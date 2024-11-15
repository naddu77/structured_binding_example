import std;

class Person
{
public:
    Person(std::string const& name, int age)
        : name{ name }, age{ age }
    {

    }

    ~Person() = default;

    std::string const& Name() const
    {
        return name;
    }

    int Age() const
    {
        return age;
    }

    template <std::size_t Index>
    requires (Index < 2)
    auto get() const
    {
        if constexpr (Index == 0)
        {
            return Name();
        }
        else if constexpr (Index == 1)
        {
            return Age();
        }
    }

private:
    std::string name;
    int age;
};

namespace std
{
    template <>
    struct tuple_size<Person>
        : integral_constant<size_t, 2>
    {

    };

    template <size_t Index>
    struct tuple_element<Index, Person>
        : tuple_element<Index, tuple<std::string, int>>
    {

    };
}

int main()
{
    Person person{ "Naddu", 18 };
    auto [name, age] { person };

    std::println("Name: {}", name);
    std::println("Age: {}", age);
}
