#include <iostream>
using namespace std;
int main()
{

  //2^r
  int LINKU[177147] = {0}, k = 0, LINKR[177147] = {0}, 
  q// nút cuối cùng thêm vào cấp k
  , s // biến dùng để chạy từ gốc-> nút hiện tại đang xét
  , nm// nút cuối cùng được thêm vào cây
  , m// nút cuối cùng được thêm vào mức hiện tại
  , n; // bien lap qua cac nut o cap do hien tai
  LINKR[0] = 1;
  LINKR[1] = 0;
  int r; //số mũ của y^r
  cout<<"Nhap r:";
  cin>>r;
  while (k < r) // vòng lặp sẽ tiếp tục cho đến cấp độ mong muốn (nút k)
  {
    n = LINKR[0]; // n được đặt thành nút đầu tiên của cấp độ hiện tại
    m = 0;        // nút cuối cùng của cấp độ hiện tại
    do
    {
      q = 0, s = n; // nút cuối cùng thêm vào cấp k + biến nút hiện tại là n
      do
      {
        if (LINKU[n + s] == 0) // nút phía trên nút hiện tại có tồn tại không
        {
          if (q == 0)       // có phải là nút cuối thêm vào cấp k hiện tại
            nm = n + s;     // nút cuối cùng thêm vào cấp k (chỉ số)
          LINKR[n + s] = q; // them mot nut ben phai nut hien tai
          LINKU[n + s] = n; // them mot nut phia tren nut hien tại
          q = n + s;        // nút cuối được thêm vào cấp k là n+s
        }
        s = LINKU[s];   // biến chạy nút ( từ gốc -> nút now) thành nút hiện tại
      } while (s != 0); // lặp từ gốc đến mức s ( s là biến chạy nút gốc- > nút đang xét) và hoàn thành các nút con bên trong mức k
      if (q != 0)       // nếu ở trên có thêm bất kỹ nút nào được tao ra trong vòng lặp
      {
        LINKR[m] = q; // nút cuối cùng của mức độ hiện tại có giấ trị là nút cuối cùng thêm vào cấp k (k này k cuối cùng vì đã thoát loop ở trên)
        m = nm;       // nút cuối cùng mức độ hiên tại( mức cuối ) đặt thành nút cuối cùng thêm vào cây
      }
      n = LINKR[n];   // n đặt thành nút mới tiếp theo ở mức k
    } while (n != 0); // vòng lặp liên tục cho đến khi các nút ở mức độ hiện tại được xử lí
    LINKR[m] = 0;     // cái nút cuói cùng trong cái tầng cấp độ đã xong hiện tại có khôing có nút R (bên phải) --> để trỏ sang cấp độ tiếp theo
    k = k + 1;        // tăng cấp độ của cây lên
  }
  cout << m;
}
// một cây gồm đệ quy nhiều cây nhỏ , nên cái giá trị m cần tính là cũng là nút cuối cùng trong một cây đẹ quy nhỏ nào đố trong một cây lớn ban đầu