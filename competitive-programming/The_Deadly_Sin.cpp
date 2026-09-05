#include <iostream>
using namespace std;

int get_remaining_chocolates(int m_chocolates, int b_chocolates){
    if (m_chocolates == b_chocolates || m_chocolates <= 0 || b_chocolates <= 0){
        if (m_chocolates < 0) m_chocolates = 0;
        if (b_chocolates < 0) b_chocolates = 0;
        return m_chocolates + b_chocolates;
    }
    else if (m_chocolates > b_chocolates){
        if (m_chocolates >= b_chocolates * 2) 
            return get_remaining_chocolates((m_chocolates % b_chocolates) + b_chocolates, b_chocolates);
        return get_remaining_chocolates(m_chocolates - b_chocolates, b_chocolates);
    }
    else {
        if (m_chocolates * 2 <= b_chocolates) 
            return get_remaining_chocolates(m_chocolates, (b_chocolates % m_chocolates)+ m_chocolates);
        return get_remaining_chocolates(m_chocolates, b_chocolates - m_chocolates);
    }
}

int main() {
    int test_cases, m_chocolates, b_chocolates;
    cin >> test_cases;
    while (test_cases--)
    {
        cin >> m_chocolates >> b_chocolates;
        cout << get_remaining_chocolates(m_chocolates, b_chocolates) << '\n';
    }
    return 0;
}

