import java.HashSet;
class Solution {
public int subarrayBitwiseORs(int[] A) {
Set ans = new HashSet();
cur.add(0);
for (int x: A) {
Set cur2 = new HashSet();
for (int y: cur)
cur2.add(x | y);
cur2.add(x);
ans.addAll(cur2);
}

    return ans.size();
}

}
