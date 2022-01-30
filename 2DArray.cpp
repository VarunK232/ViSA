#include <iostream>
using namespace std;

int main()
{
    int a[100][100];
    int m,n;
    cin>>m>>n;

    for(int i=0;i<m;i++){  //Loop for taking input row wise
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0;i<m;i++){
        cout<<endl;
        for(int j=0;j<n;j++){ //Loop for printing output row wise
        cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}