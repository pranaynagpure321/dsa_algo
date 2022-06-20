 StringBuilder seq = new StringBuilder();
       int quotient=numerator/denominator, remainder=numerator%denominator;
       seq.append(quotient);

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
               if (h1.containsKey(remainder))
               {
                   int length = h1.get(remainder);
                   seq.insert(length,"(");
                   seq.append(")");
                  break;
               }
               else
               {

                   h1.put(remainder,seq.length());
                   remainder =  remainder*10;
                   quotient = remainder/denominator;
                   remainder = remainder%denominator;

                   seq.append(quotient);
               }
           }
            h1.clear();
           return seq.toString() ;
       }
