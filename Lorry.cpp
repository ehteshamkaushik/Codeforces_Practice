#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class boat
{
public:
    long long int id;
    int type;
    int capacity;
    double perUnitCapacity;
    boat(long long int id, int type, int capacity)
    {
        this->id = id;
        this->type = type;
        this->capacity = capacity;
        perUnitCapacity = (double)capacity/(double)type;
    }
};

int main()
{
    long long int n;
    long long int v;
    cin >> n >> v;
    vector<boat> boats;
    for(long int i = 0; i < n; i++)
    {
        int t, p;
        cin >> t >> p;
        boats.push_back(boat(i+1, t, p));
    }

    sort(boats.begin(), boats.end(), []( const boat& lhs, const boat& rhs)
    {
       return lhs.perUnitCapacity > rhs.perUnitCapacity;
    });

    long long int remVolume = v;
    long long int maxCapacity = 0;
    vector<long long int> solution;
    vector<boat> solWith1;
    vector<boat> nonSolWith2;


    for(long long int i = 0; i < n; i++)
    {
        boat currentBoat = boats[i];
        if(remVolume >= currentBoat.type)
        {
            maxCapacity += currentBoat.capacity;
            remVolume -= currentBoat.type;
            solution.push_back(currentBoat.id);
            if(currentBoat.type == 1)
            {
                solWith1.push_back(currentBoat);
            }
        }
        else
        {
            if(currentBoat.type == 2)
            {
                nonSolWith2.push_back(currentBoat);
            }
        }
    }

    if((remVolume == 1) && (solWith1.size() >= 1) && (nonSolWith2.size() >= 1))
    {
        boat lastSolWith1 = solWith1[solWith1.size() - 1];
        boat firstNonSolWith2 = nonSolWith2[0];
        if(lastSolWith1.capacity < firstNonSolWith2.capacity)
        {
            for(long long int i = 0; i < solution.size(); i++)
            {
                if(solution[i] == lastSolWith1.id)
                {
                    solution.erase(solution.begin() + i);
                    break;
                }
            }
            solution.push_back(firstNonSolWith2.id);
            maxCapacity -= lastSolWith1.capacity;
            maxCapacity += firstNonSolWith2.capacity;
        }
    }
    else if((remVolume == 0) && (solWith1.size() >= 2) && (nonSolWith2.size() >= 1))
    {
        boat lastSolWith1 = solWith1[solWith1.size() - 1];
        boat secLastSolWith1 = solWith1[solWith1.size() - 2];
        boat firstNonSolWith2 = nonSolWith2[0];
        if(lastSolWith1.capacity + secLastSolWith1.capacity < firstNonSolWith2.capacity)
        {
            for(long long int i = 0; i < solution.size(); i++)
            {
                if(solution[i] == lastSolWith1.id)
                {
                    solution.erase(solution.begin() + i);
                    break;
                }
            }
            for(long long int i = 0; i < solution.size(); i++)
            {
                if(solution[i] == secLastSolWith1.id)
                {
                    solution.erase(solution.begin() + i);
                    break;
                }
            }
            solution.push_back(firstNonSolWith2.id);
            maxCapacity -= lastSolWith1.capacity;
            maxCapacity -= secLastSolWith1.capacity;
            maxCapacity += firstNonSolWith2.capacity;
        }
    }

    cout << maxCapacity << endl;
    for(long long int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << " ";
    }
}
