def make_hsp(A, N) {
  H = [];

  for(I = 0; I < N; I++) {
    F = A[I][0]*x - A[I][1]*y;
    H = append(H, [F]);
    print(H[I]);
  }

  return H;
}

def check_hsp(A, H, N) {
  INEQ = [];
  
  for(I = 0; I < N; I++) {
    F = 0;
    G = 0;
    for(J = 0; J < N; J++) {
      if(subst(H[I],x,A[J][0],y,A[J][1]) >= 0) {
	F = F + 1;
      }
      if(subst(H[I],x,A[J][0],y,A[J][1]) <= 0) {
	G = G - 1;
      }
    }
    if(F == N) {
      INEQ = append(INEQ,[1]);
    }
    else if(G == (-1)*N) {
      INEQ = append(INEQ,[-1]);
    }
    else {
      INEQ = append(INEQ,[0]);
    }
  }

  return INEQ;
}

A = newmat(3,2,[[1,1],[1,4],[4,1]]);
H = [];
INEQ = [];

H = make_hsp(A,3);
INEQ = check_hsp(A,H,3);
print("aaaaaaaaaaaaa");
print(H);
print(INEQ);


end$
