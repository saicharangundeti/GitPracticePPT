#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Control
{
    int id;
    string type;
    string state;

    void details()
    {
        cout << "Id->" << id << ", Type->"<< type <<", State->"<< state <<endl;
    }
};

class ControlsSystem
{

    vector<Control> controls;

public:
    void buildControls()
    {
        Control c1 = {1,"slider","visible"};
        Control c2 = {2,"slider","invisible"};
        Control c3 = {3,"slider","disable"};
        Control c4 = {4,"slider","visible"};
        Control c5 = {5,"slider","invisible"};
        Control c6 = {6,"button","visible"};
        Control c7 = {7,"button","invisible"};
        Control c8 = {8,"button","disable"};
        Control c9 = {9,"button","disable"};
        Control c10 = {10,"button","invisible"};

        controls.push_back(c1);
        controls.push_back(c2);
        controls.push_back(c3);
        controls.push_back(c4);
        controls.push_back(c5);
        controls.push_back(c6);
        controls.push_back(c7);
        controls.push_back(c8);
        controls.push_back(c9);
        controls.push_back(c10);
       // cout << c1.details() << endl;

    }
    // prints all the controls in the system
    void getAllControls()
    {
       // cout << "In get all control method" << endl;
        for(Control control : controls)
        {
            control.details();
        }
    }

    void findTargetId(int id)
    {
        auto targetContorl = find_if(controls.begin(),controls.end(),
                                     [id](Control &c){return c.id == id;});
        if(targetContorl != controls.end())
        {
            cout << "Id " << id << " control details are: " << "Type->"<<targetContorl->type << ", State->"<< targetContorl->state << endl;
            // targetContorl->details();

            // cout << endl;
        }
        else
        {
            cout << "id " << id <<  " not found in controls " << endl;
        }
    }

    // finds the first invisible control
    void findFirstInvisibleControl()
    {
        auto firstInvisibleControl = find_if(controls.begin(),controls.end(),
                                           [](Control &c){return c.state == "invisible";});
        if(firstInvisibleControl != controls.end())
        {
            cout << "first invisible control details are  ";
            firstInvisibleControl->details();
            cout << endl;
        }
        else
        {
            cout << "no invisible control present " << endl;
        }
    }

    void findIfAdjacentStateAreEqual()
    {
        auto adjacentStates = adjacent_find(controls.begin(),controls.end(),
                                            [](Control &c1, Control &c2) {return c1.state == c2.state; });
        if(adjacentStates != controls.end())
        {
            cout << "First adjacent pair with same state are :"<<endl;
            adjacentStates->details();
            (adjacentStates+1)->details();
        }
        else
        {
            cout <<"No adjacent cotrols with same state"<<endl;
        }
    }
    int countVisibleControls()
    {
        int count = 0;
        for(auto c : controls)
        {
            if(c.state == "visible")
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{


    ControlsSystem c;
    c.buildControls();
    c.getAllControls();
   // c.getAllControls();
    c.findFirstInvisibleControl();
    c.findTargetId(7);
    c.findTargetId(20);
    c.findIfAdjacentStateAreEqual();
    cout << c.countVisibleControls() << endl;


    // Task 1: Working with STL Algorithms
// Goal: Practice commonly used STL algorithms in the context of managing HMI control states (e.g., button visibility, slider values).
// Scenario:
// Imagine an HMI dashboard with buttons and sliders. Each control has a unique ID and a state (visible, invisible, disabled).
// Steps:
// Define the data structure:
// Create a struct Control:
// cppCopy codestruct Control {    int id;               // Unique ID    std::string type;     // "button" or "slider"    std::string state;    // "visible", "invisible", "disabled"};
// Initialize the container:
// Create a std::vector<Control> and populate it with sample controls (5 buttons and 5 sliders).
// Use the following algorithms:
// std::for_each: Iterate through all controls and print their details.
// std::find: Find a control with a specific ID.
// std::find_if: Find the first invisible control.
// std::adjacent_find: Check for consecutive controls with the same state.
// std::count: Count the number of visible controls.
// std::count_if: Count sliders that are disabled.
// std::equal: Compare two subranges of controls to check if they are identical.
// Implementation Example:
// cppCopy codeauto invisibleControl = std::find_if(controls.begin(), controls.end(),    [](const Control& ctrl) { return ctrl.state == "invisible"; });
// Output Results:
// Print the results of each algorithm in a user-friendly format.



    return 0;
}
