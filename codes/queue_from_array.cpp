 #include<bits/stdc++.h>
 using namespace std;
 #define int long long int
 int max(int a,int b)
 {
     return (a>=b?a:b);
 }
 signed main()
 {
     int t;
     t=1;
     while(t--)
     {
         int a[10];
         int front,rear;
         front=-1,
         rear=-1;
         while(1)
         {
            int ch;
            cout<<"1. Insert\n2. Pop\n3. Peep\n4. Change\n5. Display\n6. Exit\n";
            cout<<"Enter your choice: "<<" ";
            cin>>ch;
            if(ch==1)
            {
                rear++;
                if(rear==10)
                {
                    cout<<"Overflow"<<endl;
                    continue;
                }
                int num;
                cout<<"Enter the number to push: "<<" ";
                cin>>num;
                a[rear]=num;
            }
            else if(ch==2)
            {
                front++;
                if(rear<front)
                {
                    cout<<"Underflow"<<endl;
                    continue;
                }
                cout<<"removed"<<" ";
                cout<<a[front]<<endl;
            }
            else if(ch==3)
            {
                int num;
                cout<<"Enter the number to be searched: ";
                cin>>num;
                vector<int> v;
                for(int i=front;i<=rear;i++)
                {
                    if(a[i]==num)
                    v.push_back(i+1);
                }
                if(v.size()==0)
                {
                    cout<<"Not found"<<endl;
                }
                else
                {
                    cout<<"Following number is present on following index/index's :";
                    for(int i=0;i<v.size();i++)
                    cout<<v[i]<<" ";
                    cout<<endl;
                }
            }
            else if(ch==4)
            {
                int index,val;
                cout<<"Enter the index and new value: ";
                cin>>index>>val;
                index--;
                a[index]=val;
            }
            else if(ch==5)
            {
                for(int i=front+1;i<=rear;i++)
                cout<<a[i]<<" ";
                cout<<endl;
            }
            else
            {
                exit(0);
            }
         }
     }
 }
