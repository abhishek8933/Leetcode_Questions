//{ Driver Code Starts
//Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;
import java.math.*;

class Node  
{ 
    int data; 
    Node left, right; 
   
    public Node(int d)  
    { 
        data = d; 
        left = right = null; 
    } 
}

class GFG
{
    static Node buildTree(String str)
    {
        // Corner Case
        if(str.length() == 0 || str.equals('N'))
            return null;
        String[] s = str.split(" ");
        
        Node root = new Node(Integer.parseInt(s[0]));
        Queue <Node> q = new LinkedList<Node>();
        q.add(root);
        
        // Starting from the second element
        int i = 1;
        while(!q.isEmpty() && i < s.length)
        {
              // Get and remove the front of the queue
              Node currNode = q.remove();
        
              // Get the curr node's value from the string
              String currVal = s[i];
        
              // If the left child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the left child for the curr node
                  currNode.left = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.left);
              }
        
              // For the right child
              i++;
              if(i >= s.length)
                  break;
              currVal = s[i];
        
              // If the right child is not null
              if(!currVal.equals("N")) 
              {
        
                  // Create the right child for the curr node
                  currNode.right = new Node(Integer.parseInt(currVal));
        
                  // Push it to the queue
                  q.add(currNode.right);
              }
              
              i++;
        }
    
        return root;
    }
    
    public static void main(String args[]) throws IOException {
    
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while(t>0)
        {
            String s = br.readLine();
            Node root = buildTree(s);
            
            Solution T = new Solution();
            System.out.println(T.largestBst(root));
            
            t--;
        }
    }
}


// } Driver Code Ends


//User function Template for Java

// class Node  
// { 
//     int data; 
//     Node left, right; 
   
//     public Node(int d)  
//     { 
//         data = d; 
//         left = right = null; 
//     } 
// }


class Solution{
    
    static class Pair {
        public int min = 0, max = 0, count = 0;
        public boolean isBST=true;
        public Pair(int min, int max, int count, boolean isBST) {
            this.min = min;
            this.max = max;
            this.count = count;
            this.isBST = isBST;
        }
    }
    static int ans = 1;
    static Pair fn(Node root) {
        if(root == null) {
            return null;
        }
        if(root.left == null && root.right == null) {
            return new Pair(root.data, root.data, 1, true);
        } 
        Pair left = fn(root.left);
        Pair right = fn(root.right);
        
        if(left == null) {
            if(right.isBST && root.data < right.min) ans = Math.max(ans, right.count+1);
            return new Pair(Math.min(root.data, right.min), Math.max(root.data, right.max), right.count+1, right.isBST && root.data < right.min);
        }
        if(right == null) {
            if(left.isBST && root.data > left.max) ans = Math.max(ans, left.count+1);
            return new Pair(Math.min(root.data, left.min), Math.max(root.data, left.max), left.count+1, left.isBST && root.data > left.max);
        }
        
        if(left.isBST && right.isBST && root.data > left.max && root.data < right.min) {
            ans = Math.max(ans, left.count + right.count + 1);
        }
        return new Pair(Math.min(left.min, Math.min(right.min, root.data)), Math.max(left.max, Math.max(right.max, root.data)), left.count+right.count+1, left.isBST && right.isBST && root.data > left.max && root.data < right.min);
    }
    // Return the size of the largest sub-tree which is also a BST
    static int largestBst(Node root)
    {
        ans = 1;
        // Write your code here
        fn(root);
        return ans;
        
    }
    
}