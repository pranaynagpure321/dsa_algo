import java.awt.image.ImageProducer;
import java.util.HashMap;

public class Goldeman_interviewPrep {

    public static String  fractionToDecimal(int numerator, int denominator)
    {


       StringBuilder seq = new StringBuilder();
       seq.append(numerator/denominator);
       int quotient=numerator/denominator, remainder=numerator%denominator;


       if(remainder==0)
       {
           return seq.toString();
       }
       else
       {
           seq.append(".");

           HashMap<Integer,Integer> h1 = new HashMap<>();

           while (remainder!=0)
           {


               if (h1.containsKey(quotient))
               {
                   int length = h1.get(quotient);
                   seq.insert(length,"(");
                   seq.append(")");
                   return seq.toString();
               }
               else
               {

                   h1.put(quotient,seq.length());

                   remainder =  remainder*10;
                   quotient = remainder/denominator;
                   remainder = remainder%denominator;

                   seq.append(quotient);
               }
           }
            h1.clear();
           return seq.toString() ;
       }



    }

    public static String fractionToDecimal_2(int numerator, int denominator) {
        StringBuilder result = new StringBuilder();
        int quotient = numerator / denominator;
        int remainder = numerator % denominator;
        result.append(quotient);
        //this is where when, remainder is Zero that means there is nothing to check simply return quotient
        if (remainder == 0) {
            return result.toString();
        } else {
            result.append(".");
            //Creating hashmap, So, that we can store remainders and the postion of that from begining
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            while (remainder != 0) {
                if (map.containsKey(remainder)) {
                    //if it contains that means, remainder is repeating so, we will be adding ( at the length of the starting , and at the end
                    int length= map.get(remainder);
                    result.insert(length,"(");
                    result.append(")");
                    break;
                } else
                    map.put(remainder, result.length());
                //as on adding dot in the quotient in divide we add one zero rgt? yes--> therefore multiplying it by 10
                remainder *= 10;
                quotient = remainder / denominator;
                remainder = remainder % denominator;
                result.append(quotient);
            }
        }
        //as we need to return the answer in String
        return result.toString();
    }

    public static void main(String[] args) {


        System.out.println(fractionToDecimal(18,19));
        System.out.println(fractionToDecimal_2(18,19));

    }
}
