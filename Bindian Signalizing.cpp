#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long int lli;


pair<lli, lli> getSortedPair(lli a, lli b)
{
    if(a > b)
        return make_pair(a, b);
    else
        return make_pair(b, a);
}

int main()
{
    lli n;
    cin >> n;
    vector<lli> hills;
    set<pair<lli, lli> > watchmanPairs;
    for(lli i = 0; i < n; i++)
    {
        lli h;
        cin >> h;
        hills.push_back(h);
    }
    for(lli i = 0; i < n; i++)
    {
        lli currentHill = i;
        //cout << "current Hill : " << currentHill << endl;
        lli currentHillHeight = hills[i];
        //cout << "current Hill Height : " << currentHillHeight << endl;
        lli nextHill = (currentHill + 1) % n;
        //cout << "next Hill : " << nextHill << endl;
        lli nextHillHeight = hills[nextHill];
        //cout << "next Hill Height : " << nextHillHeight << endl;
        watchmanPairs.insert(getSortedPair(currentHill, nextHill));
        //cout << "Value of set : " << watchmanPairs.size() << endl;
        lli currentMaxHillHeight = nextHillHeight;
        nextHill = (nextHill + 1) % n;
        //cout << "\tnext Hill : " << nextHill << endl;
        nextHillHeight = hills[nextHill];
        //cout << "\tnext Hill Height : " << nextHillHeight << endl;
        while(nextHill != currentHill)
        {
            //cout << "Entering Loop\n";
            //int x;
            //cin >> x;
            if(currentHillHeight < currentMaxHillHeight)
            {
                //cout << "Breaking Loop\n";
                break;
            }
            if(nextHillHeight>= currentMaxHillHeight)
            {
                watchmanPairs.insert(getSortedPair(currentHill, nextHill));
                //cout << "\tValue of set : " << watchmanPairs.size() << endl;
                currentMaxHillHeight = nextHillHeight;
            }
            nextHill = (nextHill + 1) % n;
            //cout << "\tnext Hill : " << nextHill << endl;
            nextHillHeight = hills[nextHill];
            //cout << "\tnext Hill Height : " << nextHillHeight << endl;

        }
    }

    cout << watchmanPairs.size();
    return 0;
}
