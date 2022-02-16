//boggle is a popular word game in which players attempt to find words in sequences of adjacent letters on a rectangular board.
//Given a two-dimensional array board that represents the character cells of the Boggle board and an array of unique strings words, 
//find all the possible words from words that can be formed on the board.

//Note that in Boggle when you're finding a word, you can move from a cell to any of its 8 neighbors, but you can't use the same cell twice in one word.

//Example

//For

//board = [
//    ['R', 'L', 'D'],
//    ['U', 'O', 'E'],
 //   ['C', 'S', 'O']
//]
//and words = ["CODE", "SOLO", "RULES", "COOL"], the output should be
//solution(board, words) = ["CODE", "RULES"].


import java.util.*;

public class wordBogglt {

    public  static List<String> ll = new LinkedList<String>();
    public  static  String[] solution(char[][] board, String[] words) {

        for(String str : words){
            aa:
            for(int i =0 ;i<board.length;i++) {
                bb:
                for (int j = 0; j < board[0].length; j++) {
                    if (board[i][j] == str.charAt(0)) {
                        boolean[][] visited = new boolean[board.length][board[0].length];
                        visited[i][j]=true;
                       boolean flag =  boogle(i, j, str, board, visited, 0);
                       if(flag==true)
                           break aa;
                    }
                }
            }
        }
        //System.out.print(ll.size());
        String[]arr =new String[ll.size()];
        for(int i=0; i< ll.size();i++)
        {
            arr[i]= ll.get(i);
        }
        ll.clear();
        Arrays.sort(arr);
        return arr;
    }

    public  static  boolean boogle(int row,int col,String word,char[][] board, boolean[][] visited,int Position)
    {
        if(Position==word.length()-1)
        {
            ll.add(word);
            return true;
        }
        else if(Position > word.length()-1)
            return false;

        LinkedList<Integer> list= new LinkedList<>();
        checkAt(row,col,word.charAt(Position+1),list,board) ;

        for(int i=0;i<list.size();i += 2)
        {
            row = (int)list.get(i);
            col = (int)list.get(i+1);
            if(visited[row][col]!=true) {
                visited[row][col] = true;
                if(boogle(row, col, word, board, visited, Position + 1))
                    return true;
                visited[row][col] = false;
            }
        }
        return false;
    }

    public  static  void checkAt(int row,int col,char c, LinkedList<Integer> list,char[][] board)
    {

        // upleftdiagonal
        if(row-1>=0 && col-1>=0 && board[row-1][col-1]==c){
            list.addLast(row-1);
            list.addLast(col-1);
        }
        //up
        if(row-1>=0 && board[row-1][col]==c){
            list.addLast(row-1);
            list.addLast(col);

        }
        // uprightdiagonal
        if(row-1>=0 && col+1<board[0].length && board[row-1][col+1]==c){
            list.addLast(row-1);
            list.addLast(col+1);

        }
        //left
        if(col-1>=0 && board[row][col-1]==c){
            list.addLast(row);
            list.addLast(col-1);

        }
        //right
        if(col+1<board[0].length && board[row][col+1]==c){
            list.addLast( row);
            list.addLast(col+1);

        }
        //downleftdiagonal
        if(row+1<board.length && col-1>=0 && board[row+1][col-1]==c){
            list.addLast(row+1);
            list.addLast( col-1);

        }
        //down
        if(row+1<board.length && board[row+1][col]==c){
            list.addLast(row+1);
            list.addLast(col);

        }
        //downrightdiagonal
        if(row+1<board.length && col+1<board[0].length && board[row+1][col+1]==c){
            list.addLast( row+1);
            list.addLast( col+1);

        }
    }


    public static void main(String[] args) {
        String[] words= {"CODE", "SOLO", "RULES", "COOL"};
        char[][] board = {
                {'R', 'L', 'D'},
                {'U', 'O', 'E'},
                {'C', 'S', 'O'}};

        String[] arr =solution(board,words);
        System.out.println(Arrays.toString(arr));

    }

}
