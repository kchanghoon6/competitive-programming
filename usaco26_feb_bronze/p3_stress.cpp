#include <bits/stdc++.h>
using namespace std;

mt19937 rng(42);

int randint(int lo, int hi){
   return uniform_int_distribution<int>(lo, hi)(rng);
}

// 전체 문자에서 목표 문자열 생성
string gen_test(int n, int m, int alpha){
   vector<string> S(n);
   for(int i = 0; i < n; i++){
      S[i].resize(m);
      for(int j = 0; j < m; j++)
         S[i][j] = 'a' + randint(0, alpha - 1);
   }

   vector<char> pool;
   for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
         pool.push_back(S[i][j]);

   shuffle(pool.begin(), pool.end(), rng);
   string t(pool.begin(), pool.begin() + m);
   shuffle(t.begin(), t.end(), rng);

   ostringstream oss;
   oss << n << " " << m << "\n";
   for(int i = 0; i < n; i++)
      oss << S[i] << "\n";
   oss << t << "\n";
   return oss.str();
}

// Run solution on input, return output
string run_solution(const string& input, const string& sol_path){
   // Write input to temp file
   FILE* f = fopen("/tmp/p3_stress_in.txt", "w");
   fprintf(f, "1\n%s", input.c_str());
   fclose(f);

   string cmd = sol_path + " < /tmp/p3_stress_in.txt > /tmp/p3_stress_out.txt 2>&1";
   int ret = system(cmd.c_str());
   if(ret != 0){
      return "RUNTIME_ERROR";
   }

   // Read output
   ifstream fin("/tmp/p3_stress_out.txt");
   ostringstream oss;
   oss << fin.rdbuf();
   return oss.str();
}

// Parse test input
struct TestCase {
   int n, m;
   vector<string> S; // 1-indexed
   string t;
};

TestCase parse_input(const string& input){
   istringstream iss(input);
   TestCase tc;
   iss >> tc.n >> tc.m;
   tc.S.resize(tc.n + 1);
   for(int i = 1; i <= tc.n; i++) iss >> tc.S[i];
   iss >> tc.t;
   return tc;
}

struct Op {
   int type, a, b, c; // type 1: swap within S[a] positions b,c (1-indexed)
                      // type 2: swap S[a][c] and S[b][c] (1-indexed for string indices, 1-indexed for position)
};

// Parse solution output
pair<int, vector<Op>> parse_output(const string& output){
   istringstream iss(output);
   int k;
   if(!(iss >> k)) return {-1, {}};
   vector<Op> ops(k);
   for(int i = 0; i < k; i++){
      iss >> ops[i].type >> ops[i].a >> ops[i].b >> ops[i].c;
   }
   return {k, ops};
}

// Verify
string verify(const TestCase& tc, int k, const vector<Op>& ops){
   if(k < 0) return "PARSE_ERROR: couldn't parse output";
   if(k > 2 * tc.m) return "TOO_MANY_OPS: " + to_string(k) + " > " + to_string(2 * tc.m);
   if((int)ops.size() != k) return "OP_COUNT_MISMATCH";

   vector<string> S = tc.S; // copy, 1-indexed

   for(int idx = 0; idx < k; idx++){
      auto& op = ops[idx];
      if(op.type == 1){
         // swap within string op.a, positions op.b and op.c (1-indexed)
         int i = op.a, a = op.b, b = op.c;
         if(i < 1 || i > tc.n) return "OP" + to_string(idx) + ": string index " + to_string(i) + " out of range";
         if(a < 1 || a > tc.m || b < 1 || b > tc.m)
            return "OP" + to_string(idx) + ": position out of range";
         swap(S[i][a - 1], S[i][b - 1]);
      } else if(op.type == 2){
         // swap S[op.a][op.c] and S[op.b][op.c] (1-indexed)
         int i = op.a, j = op.b, pos = op.c;
         if(i < 1 || i > tc.n || j < 1 || j > tc.n)
            return "OP" + to_string(idx) + ": string index out of range";
         if(pos < 1 || pos > tc.m)
            return "OP" + to_string(idx) + ": position " + to_string(pos) + " out of range";
         swap(S[i][pos - 1], S[j][pos - 1]);
      } else{
         return "OP" + to_string(idx) + ": unknown type " + to_string(op.type);
      }
   }

   if(S[1] != tc.t){
      return "WRONG_ANSWER: s1=" + S[1] + " expected=" + tc.t;
   }
   return "OK";
}

int main(int argc, char** argv){
   string sol_path = "/tmp/p3_sol";
   if(argc > 1) sol_path = argv[1];

   int total = 0, passed = 0, failed = 0;

   // Manual edge cases first
   vector<string> manual_tests = {
      // N=1, M=1, s1 already equals t
      "1 1\na\na\n",
      // N=1, M=3, only within-s1 swaps
      "1 3\nabc\ncba\n",
      // N=2, M=1, between-string swap
      "2 1\na\nb\nb\n",
      // All strings identical to t, 0 ops needed
      "3 3\nabc\nabc\nabc\nabc\n",
      // N=1, M=3, already equal
      "1 3\nabc\nabc\n",
      // N=1, M=4, reverse
      "1 4\nabcd\ndcba\n",
      // N=2, M=3, need chars from s2
      "2 3\naaa\nbbb\nbba\n",
      // N=1, M=2, simple swap
      "1 2\nab\nba\n",
      // N=2, M=2, mixed
      "2 2\nab\ncd\nca\n",
      // N=3, M=2
      "3 2\nab\ncd\nef\nea\n",
   };

   cout << "=== Manual Edge Cases ===" << endl;
   for(auto& test : manual_tests){
      total++;
      TestCase tc = parse_input(test);
      string output = run_solution(test, sol_path);
      if(output == "RUNTIME_ERROR"){
         cout << "FAIL (runtime error) on test:" << endl << test << endl;
         failed++;
         continue;
      }
      auto [k, ops] = parse_output(output);
      string result = verify(tc, k, ops);
      if(result == "OK"){
         cout << "OK  (ops=" << k << ") n=" << tc.n << " m=" << tc.m << endl;
         passed++;
      } else{
         cout << "FAIL: " << result << endl;
         cout << "Input:\n" << test;
         cout << "Output:\n" << output;
         failed++;
      }
   }

   // Random stress tests
   cout << "\n=== Random Stress Tests ===" << endl;
   int num_random = 50000;
   for(int iter = 0; iter < num_random; iter++){
      int n = randint(1, 4);
      int m = randint(1, 6);
      int alpha = randint(2, 3);
      string test = gen_test(n, m, alpha);

      total++;
      TestCase tc = parse_input(test);
      string output = run_solution(test, sol_path);
      if(output == "RUNTIME_ERROR"){
         cout << "FAIL (runtime error) on test #" << iter << ":" << endl << test << endl;
         failed++;
         if(failed >= 5){ cout << "Too many failures, stopping." << endl; break; }
         continue;
      }
      auto [k, ops] = parse_output(output);
      string result = verify(tc, k, ops);
      if(result == "OK"){
         passed++;
         if((iter + 1) % 5000 == 0)
            cout << "Passed " << (iter + 1) << " random tests..." << endl;
      } else{
         cout << "FAIL on random test #" << iter << ": " << result << endl;
         cout << "Input:\n" << test;
         cout << "Output:\n" << output;
         failed++;
         if(failed >= 5){ cout << "Too many failures, stopping." << endl; break; }
      }
   }

   cout << "\n=== Summary ===" << endl;
   cout << "Total: " << total << "  Passed: " << passed << "  Failed: " << failed << endl;
   return failed > 0 ? 1 : 0;
}
