/*
--The Virtual Destructor Test--

Create a base class Resource and two derived classes, FileResource and NetworkResource.

The base class must have a virtual destructor, and each class must print its destructor message.

Create objects using base-class pointers and delete them in input order. The derived-class destructor must execute before the base-class destructor.

Input Format

The first line contains an integer (N), the number of resources.
The next (N) lines contain one character:
F — File resource
N — Network resource
Constraints

1 <= N <= 100
Resource type must be F or N.
Objects must be deleted through base-class pointers.
The base-class destructor must be virtual.
Output Format

For each resource, print its derived-class destructor message followed by Resource destructor.

File: FileResource destructor
Network: NetworkResource destructor
Base: Resource destructor
Sample Input 0

2
F
N
Sample Output 0

FileResource destructor
Resource destructor
NetworkResource destructor
Resource destructor
*/

#include <vector>
#include <iostream>
using namespace std;

class Resource{
    private:
        
    public:
        virtual ~Resource(){
            cout<<"Resource destructor"<<endl;
        }
};

class FileResource : public Resource{
    private:
        
    public:
        ~FileResource() override{
            cout<<"FileResource destructor"<<endl;
        }
};

class NetworkResource : public Resource{
    private:
        
    public:
        ~NetworkResource() override{
            cout<<"NetworkResource destructor"<<endl;
        }
};

int main() {
    int n;
    cin>>n;
    
    vector<Resource*> resources;
    
    for (int i = 0; i < n; ++i) {
            char type;
            cin >> type;
            if (type == 'F') {
                resources.push_back(new FileResource());
            } else if (type == 'N') {
                resources.push_back(new NetworkResource());
            }
    }
    
    for (Resource* rec : resources) {
        delete rec; 
    }
    
    return 0;
}
