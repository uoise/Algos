class Solution {
    static final int[] sale = {10, 20, 30, 40};

    public int getSalePrice(int price, int saleIdx) {
        return price * (100 - sale[saleIdx]) / 100;
    }

    public int[] solution(int[][] users, int[] emoticons) {
        int plsMax = -1, sumMax = -1;
        for (int saleIdx = 0; saleIdx < (int) Math.pow(4, emoticons.length + 1); saleIdx++) {
            int plsCnt = 0, buySum = 0;
            for (int[] user : users) {
                int usrBuy = 0, tmpIdx = saleIdx;
                for (int emoticon : emoticons) {
                    if (sale[tmpIdx % 4] >= user[0]) {
                        usrBuy += getSalePrice(emoticon, tmpIdx % 4);
                    }
                    if (usrBuy >= user[1]) {
                        plsCnt++;
                        usrBuy = 0;
                        break;
                    }
                    tmpIdx /= 4;
                }
                buySum += usrBuy;
            }
            if (plsCnt > plsMax) {
                plsMax = plsCnt;
                sumMax = buySum;
            } else if ((plsCnt == plsMax) && (buySum > sumMax)) {
                sumMax = buySum;
            }
        }
        return new int[]{plsMax, sumMax};
    }
}