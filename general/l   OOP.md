______________________________________________________________________________________________________
prperties ( get , put )

__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;


Person1.SetFirstName("Mohammed");
cout << Person1.GetFirstName() << "\n";

//instead of the above we only write this
Person1.FirstName = "Mohammed";
cout << Person1.FirstName;


_____________________________________________________________________________________________________
////////////////  static member
// public or private
// declared in the class and defined outside it
// accessed via ClassName::member without an object , or through an existing object. 
// Private access rules still apply.

////////////////  static method
// public or private
// accessed via ClassName::member without an object , or through an existing object. 
// Private access rules still apply.
// Directly accesses static members ; non-static members require an object.


/////////////////  constructor


Derived(parameters)
    : Base(arguments_passed_to_base_constructor)
{
    // derived initialization
}

// if the base class has only a parameterized constructor, every derived constructor must initialize the base by calling that constructor ( with all of its  parameters )
// Or, if the base class also has a default constructor : The derived constructor can expose all , some or non of base constructor parameters or even new parameters
// practically , when i made a class , if i intend to do a constructor for it and intend to do a customized constructor for a derived class , better use 2 constructor ( one of them is empty )