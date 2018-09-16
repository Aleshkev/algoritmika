#include <iostream>
#include <map>
#include <set>

using namespace std;

typedef long long int I;

struct Exercise {
    Exercise(I t_, I l_, I i_) : t(t_), l(l_), l_copy(l_), i(i_) {};
    I t, l, l_copy;
    I i;
};

struct by_t { const bool operator() (const Exercise &l, const Exercise &r) const { return l.t < r.t; }; };
struct by_l { const bool operator() (const Exercise &l, const Exercise &r) const { return l.l < r.l; }; };

int main()
{
    cout.sync_with_stdio(false);

    I n, m;
    cin >> n >> m;

    set<I> events;

    multiset<Exercise, by_t> exercises;
    for(I i = 0; i < n; ++i) {
        I t, l;
        cin >> t >> l;
        exercises.insert(Exercise(t, l, i));
        events.insert(t);
    }
    events.insert(m - 1);

    I c = 0;
    multiset<Exercise, by_l> pending;
    multiset<Exercise, by_t> completed;
    I last_time = 0;
    for(set<I>::iterator i = events.begin(); i != events.end(); ++i) {

        I current_time = *i;
        I time_delta = current_time - last_time;
        last_time = current_time;

        while(!exercises.empty() && exercises.begin()->t <= current_time) {
            pending.insert(*exercises.begin());
            exercises.erase(exercises.begin());
        }

        if(!pending.empty() && time_delta > 0) {
            Exercise exercise = *pending.begin();
            pending.erase(pending.begin());

            exercise.l -= time_delta;

            if(exercise.l <= 0) {
                time_delta = -exercise.l;
                ++c;
                completed.insert(exercise);
            } else {
                time_delta = 0;
                pending.insert(exercise);
            }
        }
    }

    /*Exercise current = *exercises.begin();
    I i = current.t;
    I last_i = 0;
    while(!events.empty()) {
        while(!exercises.empty() && exercises.begin()->t <= i) {
            pending.insert(*exercises.begin());
            exercises.erase(exercises.begin());
        }
        last_i = i;
        i = *events.begin();
        events.erase(events.begin());
        I delta_i = i - last_i;
        if(!pending.empty()) {
            Exercise exercise = *pending.begin();
            pending.erase(pending.begin());
            exercise.l -= delta_i;
            if(exercise.l <= 0) {
                ++c;
                completed.insert(exercise);
            } else {
                pending.insert(exercise);
            }
        }
    }*/

    cout << c << '\n';

    I h = 0;
    for(multiset<Exercise>::iterator i = completed.begin(); i != completed.end(); ++i) {
        I time = max(h, i->t);
        cout << i->i + 1 << ' ' << time << '\n';
        h = time + i->l_copy;
    }

    return 0;
}
