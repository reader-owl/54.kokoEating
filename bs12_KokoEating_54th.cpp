#include <iostream>

/*
                Q. Koko eating bananas
                 
            explanation -  return the minimum integer 'k' such that Koko can eat all bananas w/i 'h' hours

                                piles[] = {3, 6, 7, 11}     h = 8
                            where, there are certain nmbr of bananas in each piles (in 1st piles there's 3 bananas)
                                    'h' is numbr of hours which is 8
                            koko have to eat the maximum nmbr of bananas in the time limit
                            koko can't move pile nmbr 2 if she haven't finished pile nmbr 1

                            so we have to find out minimum nmbr of 'k',     k -> bananas/hr

                            if k = 2 bananas/hr, then pile with 3 bananas will take -> 3/2hr = 1.5hr = 2hr (ceiling value)
                                            then pile with 6 bananas will take -> 6/2hr = 3hr = 3hr (ceiling value)
                                            then pile with 7 bananas will take -> 7/2hr = 3.5hr = 4hr (ceiling value)
                                            then pile with 11 banana will take -> 11/2hr = 5.5hr = 6hr (ceiling value)
                                        then total time taken = 2 + 3 + 4 + 6
                                                              = 15hr    which exceeded our time limit

                            similarly for k = 3 bananas/hr will take = 1 + 2 + 3 + 4
                                                                     = 10hr     which also exceed our time limit

                            similarly for k = 4 bananas/hr will take = 1 + 2 + 2 + 3
                                                                     = 8hr     which is within our time limit

                                    so w have to find this minimum nmbr of 'k' using code 


                    Brute force -  we will start with 1 banana and increase it till we got our deadline time

                              maximum nmbr of banana can be eaten per hour will '11', bcz by eating 11 banana per hour will
                              take 1 + 1 + 1 + 1 = 4hr,   if it is more than 11 banana per hr then it will also take 4hr
                              so our maximum banana/hr will be '11' and minimum is '1' banana/hr

        Pseudo code
func(arr, hourly)
{
    totalHours = 0
    for(i=0->n-1)
    {
        totalHours += ceil(arr[i]/hourly);
    }
    return totalHours
}
for(i=1->max(arr))
{
    reqTime = func(arr, i)                          // we have defined the function above
    if(reqTime <= h)
        return i;
}


            TC - O(max(arr) * N)                // <- this will give Time Limit Exceeded


                Optimal sol -  we will be using binary search
                                and the range will be from from '1' to maximum nmbr of banana in largest pile

                            which means low = 1, high = 11  then mid = 6
                            with '6' the piles will take    (1 + 1 + 2 + 2)hrs = 6 hrs
                                so '6' is the possible answer, lets store it in a variable ans = 6

                            questions states that we have to find minimum nmbr of 'k' so we will eliminate the right
                            and take low = 1, high = 5  then mid = 3
                            with '3' the piles will take    (1 + 2 + 3 + 4)hrs = 10 hrs
                                which exceeded our limit so '3' is not our possible answer
                            we will eliminate left bcz if '3' exceed our limit then '2' will take even more time

                            then take low = 4, high = 5  then mid = 4
                            with '4' the piles will take    (1 + 2 + 2 + 3)hrs = 8hrs
                                '4' is also a possble answer and is minimum so we update our ans = 4

                            if 4 is our possible answer than 5 can also be our possible answer but we found our minimum possible
                            answer and 5 will gives us answer greater than 4 so high will get to 3 that means high crosses low
                            by this our binary search ends here

                            from above algorithm in by binary search  we can say that 1, 2, 3 were not our possible answer
                            and from '4' to '11' were our possible answers and the maximum '11' is our most possible answer


        Pseudo code
func(arr, hourly)
{
    totalHours = 0
    for(i=0->n-1)
    {
        totalHours += ceil(arr[i]/hourly);
    }
    return totalHours
}
bs(arr, h)                              // binary search
{
    low = 1, high = maxEl(arr);
    ans = INT_MAX;

    while(low <= high)
    {
        mid = (low + high) / 2;
        totalHrs = func(arr, mid);          // we have defined the function above
        if(totalhrs <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}


            TC - [O(N) * (log base2 (maxEl))]


        Actual code
int findMax(vector<int> &v)
{
    int maxi = INT_MIN;
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalH = 0;
    int n = v.size();
    for(int i = 0; i < n; i++)
    {
        totalH += ceil((double)v[i] / (double)hourly);
    }
    return totalH;
}

int minimumRateToEatBananas(vector<int> v, int h)
{
    int low = 1, high = findMax(v);
    while(low <= high)
    {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if(totalH <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
*/

int main()
{
    std::cout << "Hello World!\n";
}