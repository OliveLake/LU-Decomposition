#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
/*bool checkU(vector<double> U,int i){
    bool a=false,b=false,c=false;
    int count = 0;
    vector<double>::iterator it;
    it = U.begin();cout<<U.begin(); it<U.end();   cout<<U.end();

    for(int j=0;j<i;j++)
    {
        for(it = U.begin();it<U.end();it++)
        {
            if(*it == 0)    count++;
        }
    }
    if(a&b&c)       return 1;
    else return 0;
}//確定U*/


int main()
{
    fstream fin("input.txt");
    if ( ! fin)
    {
    cout << "failed" <<endl;
    }
    else
    {
        cout<<"sucessed"<<endl;
        vector<double>::iterator it1;
        int time,nThird,nSec,nFirst,grid;
        double c,mup,Lmup;
            fin>>time;
        fstream fout("output.txt");
        fout<<time<<"\n";
        for(int i=0;i<time;i++)
        {   cout<<"i:"<<i;
            fout<<"True"<<"\n";
            fin >>nSec>>nFirst;
            if(nSec>nFirst) grid = nFirst;
            else    grid = nSec;
            vector<double> matrix[nSec];
            vector<vector<double> > matrixL(nSec,vector<double>(nSec,0));
            vector<double> matrixU[nSec];

            for (int j = 0; j < nSec; j++)
            {
                
                for (int k = 0; k < nFirst; k++)
                {
                    fin>>c;
                    matrix[j].push_back(c);
              //      matrixL[j].push_back(0);//L
                    matrixU[j].push_back(c);//U

                }//initial
                for(it1 = matrix[j].begin();it1<matrix[j].end();it1++)
                               cout<<*it1<<' ';
                cout<<endl; //check
                
            }
            
            //find U/L 1st row
            for(int j = 1; j < nFirst+1 ;j++)
            {
                mup  =  matrixU[j][0]/matrixU[0][0];
                for(int k = 0; k < nFirst ; k++)
                {
                  //  if(j >= nFirst)   break;
                    matrixU[j][k] += -mup;
                   
                }
                matrixL[j][0] = mup;
                cout<<"mup:"<<mup<<endl;

            }
            //print
            for(int j=0;j<nSec;j++){
                for(it1 = matrixU[j].begin();it1<matrixU[j].end();it1++)
                {
                    cout<<*it1<<' ';
                    i++;
                }
                cout<<endl; //check
            }
            for(int j=0;j<nSec;j++){
                for(it1 = matrixL[j].begin();it1<matrixL[j].end();it1++)
                {
                    cout<<*it1<<' ';
                    i++;
                }
                cout<<endl; //check
            }

            //find U/L 2st row

            for(int j = 2; j < nFirst ;j++)
            {
            
                mup = matrixU[j][1]/matrixU[1][1];
                matrixL[j][1] = mup;
                Lmup = matrixU[j+1][1]/matrixU[1][1];
                for(int k = 1; k < nFirst ; k++)
                {
                  //  if(j >= nFirst)   break;
                    matrixU[j][k] += -mup*matrixU[1][k];
                }
                for(int k = 1; k < nFirst ; k++)
                {
                  //  if(j >= nFirst)   break;
                    matrixU[j+1][k] += -Lmup*matrixU[1][k];
                }
                
                matrixL[j+1][1] = Lmup;
             //   cout<<"mup:"<<mup<<endl;
                    
            }
        //    mup = matrixU[nFirst][nFirst]/matrixU[nFirst+1][nFirst];
  //          cout<<"mup:"<<mup<<endl;
  //          matrixL[nSec+3][nFirst-1] = mup;

            //print
            for(int j=0;j<nSec;j++){
                for(it1 = matrixU[j].begin();it1<matrixU[j].end();it1++)
                {
                    cout<<*it1<<' ';
                    i++;
                }
                cout<<endl; //check
            
            }
            for(int j=0;j<nSec;j++){
                for(it1 = matrixL[j].begin();it1<matrixL[j].end();it1++)
                {
                    cout<<*it1<<' ';
                    i++;
                }
                cout<<endl; //check
            }
            
            matrixL[nSec-1][nSec-1-1] = matrixU[nSec-1][nFirst-1]/matrixU[nSec-1-1][nFirst-1];
            for(int j=0;j<nSec;j++){
                for(it1 = matrixL[j].begin();it1<matrixL[j].end();it1++)
                {
                    cout<<*it1<<' ';
                    i++;
                }
                cout<<endl; //check
            }
            for(int j=0;j<nSec;j++){
                matrixL[j][j] = 1;
            }
            
            fout<<nSec<<" "<<nSec<<"\n";
            for(int j=0;j<nSec;j++){
                for(it1 = matrixL[j].begin();it1<matrixL[j].end();it1++)
                {
                    fout<<*it1<<" ";
                }
                fout<<"\n";
            }
            fout<<nSec<<" "<<nFirst<<"\n";
            for(int j=0;j<nSec;j++){
                for(it1 = matrixU[j].begin();it1<matrixU[j].end();it1++)
                {/Users/User/Downloads/F74080000_姓名_HW2
                    fout<<*it1<<" ";
                }
                fout<<"\n";
            }
        }
        
    fin.close();
   
}
    
    return 0;
}

