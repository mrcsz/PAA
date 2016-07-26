#include <bits/stdc++.h>
using namespace std;

int cont = 0;

void transformacao(vector<vector<char> > matx, int l, int c);
vector<vector<char> > initSub(vector<vector<char> > M, vector<vector<char> > Msub, int Lsub, int Csub, int L0, int C0);
vector<vector<char> > initM(vector<vector<char> > M, int L, int C);
bool chec(vector<vector<char> > matx, int L, int C);

int main()
{
    int quant, L, C;
    bool um = false;
    bool zero = false;

    cin >> quant;

    vector<vector<char> > bitmap;


    for(int z = 0; z < quant; z++)
    {

        cont = 0;
        cin >> L;
        cin >> C;
        um = false;
        zero = false;
        //-------------inicializando --------

        bitmap.resize(L);
        for(int i = 0; i < L; i++)
        {
            bitmap[i].resize(C);
        }
        //-----------------end initial ------

        for(int i = 0; i < L; i++)
        {
            for(int j = 0; j < C; j++)
            {
                cin >> bitmap[i][j];

                if(bitmap[i][j] == '0') zero = true;
                else um = true;

            }
            getchar();
        }

        if(((um && !zero) || (!um && zero) || (L == 1 && C == 1)))
        {
            if(um)
            {
                cout << '1';
                cont++;
                if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }
            }
            else
            {
                cout << '0';
                cont++;
                if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }
            }
        }
        else
        {
            transformacao(bitmap, L, C);
        }
		cout << endl;
    }




    return 0;
}


void transformacao(vector<vector<char> > matx, int L, int C)
{
    if(L == 0 || C == 0) return;
//--------- one element ---------------
    if(L <= 1 && C <= 1)
    {
        if(matx[0][0] == '0')
        {
            cout << '0';
            cont++;
            if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }
            return;
        }
        else
        {
            cout << '1';
            cont++;
            if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }
            return;
        }
    }

//------------- end (one element) ----------------------

	if(chec(matx, L, C)) return;
	cout << 'D';
	cont++;
    if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }

    int i, j;
    int l1 = 0, c1 = 0, l2 = 0, c2 = 0;

    vector<vector<char> > m1;
    vector<vector<char> > m2;
    vector<vector<char> > m3;
    vector<vector<char> > m4;


    //------ verification size subarray ---------------
    if(L%2 == 0 && C == L)
    {

        l1 = l2 = c1 = c2 = L/2;
    }
    else if(L%2 == 1 && C%2 == 0)
    {
        l1 = L/2 + 1;
        l2 = L/2;
        c1 = c2 = C/2;
    }
    else if(L%2 == 0 && C%2 == 1)
    {
        l1 = l2 = L/2;
        c1 = C/2 + 1;
        c2 = C/2;
    }
    else if(L%2 == 1 && C%2 == 1)
    {
        l1 = L/2 + 1;
        l2 = L/2;
        c1 = C/2 + 1;
        c2 = C/2;

    }
    else if(L%2 == 0 && C%2 == 0)
    {
        l1 = L/2;
        l2 = L/2;
        c1 = C/2;
        c2 = C/2;
    }

    m1 = initM(m1, l1, c1);
    m2 = initM(m2, l1, c2);
    m3 = initM(m3, l2, c1);
    m4 = initM(m4, l2, c2);


    //cout << m1.size();

    m1 = initSub(matx, m1, l1, c1, 0, 0);
    m2 = initSub(matx, m2, l1, c2, 0, c1);
    m3 = initSub(matx, m3, l2, c1, l1, 0);
    m4 = initSub(matx, m4, l2, c2, l1, c1);


    transformacao(m1, l1, c1);
    transformacao(m2, l1, c2);
    transformacao(m3, l2, c1);
    transformacao(m4, l2, c2);

}

bool chec(vector<vector<char> > matx, int L, int C)
{
	bool um = false;
	bool zero = false;

	for(int i = 0; i < L; i++)
        {
            for(int j = 0; j < C; j++)
            {

                if(matx[i][j] == '0') zero = true;
                else um = true;

            }
        }

	if(((um && !zero) || (!um && zero)))
        {
            if(um)
            {
                cout << '1';
                cont++;
                if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }
				return true;
            }
            else
            {
                cout << '0';
                cont++;
                if(cont >= 50)
                {
                     cout << endl;
                     cont = 0;
                }
				return true;
            }
        }
        else
        {
            return false;
        }
}

vector<vector<char> > initSub(vector<vector<char> > M, vector<vector<char> > Msub, int Lsub, int Csub, int L0, int C0)
{

    for(int i = 0; i < Lsub; i++)
    {
        for(int j = 0; j < Csub; j++)
        {

            Msub[i][j] = M[i + L0][j + C0];
        }
    }
    return Msub;
}

vector<vector<char> > initM(vector<vector<char> > M, int L, int C)
{
    M.resize(L);
    for(int i = 0; i < L; i++)
    {
        M[i].resize(C);
    }
    return M;
}

