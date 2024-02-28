class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int k =0, l = 0;
        List<Integer> result = new ArrayList<>();
        while(k < m && l < n){
            for(int i=l; i<n; i++){
                result.add(matrix[k][i]);
            }
            k++;
            for(int j=k; j<m; j++){
                result.add(matrix[j][n-1]);
            }
            n--;
            if(k<m){
                for(int i=n-1; i>=l; i--){
                    result.add(matrix[m-1][i]);
                }
                m--;
            }
            if(l<n){
                for(int j=m-1; j>=k; j--){
                    result.add(matrix[j][l]);
                }
                l++;
            }
        }
        return result;   
    }
}