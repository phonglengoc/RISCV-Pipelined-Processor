// `timescale 1ns / 1ns


// module gp1(
// input wire a, b,
// output wire g, p
//     );
//    assign g = a & b;
//    assign p = a | b;
    
// endmodule

// module gp_4(
// input wire [3:0] gin, pin,
// input wire cin,
// output wire gout, pout,
// output wire [2:0] cout
//     );
//     wire [3:0] g;
//     wire [3:0] p;
    
//     // carry
//     gp1 u0(.a(gin[0]),.b(pin[0]),.g(g[0]),.p(p[0]));
//     gp1 u1(.a(gin[1]),.b(pin[1]),.g(g[1]),.p(p[1]));
//     gp1 u2(.a(gin[2]),.b(pin[2]),.g(g[2]),.p(p[2]));
//     gp1 u3(.a(gin[3]),.b(pin[3]),.g(g[3]),.p(p[3]));
    
//     assign cout[0] = g[0] | (p[0] & cin);
//     assign cout[1] = g[1] | (p[1]&cout[0]);
//     assign cout[2] = g[2] | (p[2] & cout[1]);
//     // Group generate (carry-out của block)
//     assign gout = g[3]
//                 | (p[3] & g[2])
//                 | (p[3] & p[2] & g[1])
//                 | (p[3] & p[2] & p[1] & g[0])
//                 | (p[3] & p[2] & p[1] & p[0] & cin);

//     // Group propagate
//     assign pout = p[3] & p[2] & p[1] & p[0];
//     assign gout = g[3] | 
//         (p[3] & g[2]) | 
//         (p[3] & p[2] & g[1]) | 
//         (p[3] & p[2] & p[1] & g[0]);
    
// endmodule

// module gp_8(
// input wire [7:0] gin, pin,
// input wire cin,
// output wire gout, pout,
// output wire [6:0] cout
//     );
//     wire gout_low, pout_low, gout_high, pout_high;
    
//     wire [2:0] cout_low;
//     wire [2:0] cout_high;
    
//     gp_4 gp_low(
//         .gin(gin[3:0]),
//         .pin(pin[3:0]),
//         .cin(cin),
//         .cout(cout_low),
//         .gout(gout_low),
//         .pout(pout_low)
//     );
//     assign cout[3] = gout_low | (pout_low & cin);
//     gp_4 gp_high (
//         .gin(gin[7:4]),
//         .pin(pin[7:4]),
//         .cin(cout[3]),
//         .gout(gout_high),
//         .pout(pout_high),
//         .cout(cout_high)
//     );
//     assign cout[2:0] = cout_low[2:0];
//     assign cout[6:4] = cout_high[2:0];
    
//     assign pout = pout_high & pout_low;
//     assign gout = gout_high | (pout_high & gout_low);

// endmodule

// module cla(
//    input wire [31:0]  a, b,
//    input wire         cin,
//    output wire [31:0] sum
//     );
//     // --- Stage 1: bit-level generate & propagate ---
//     wire [31:0] g, p;
//     genvar i;
//     generate
//         for (i = 0; i < 32; i = i + 1) begin : gp1_stage
//             gp1 u_gp1 (
//                 .a(a[i]),
//                 .b(b[i]),
//                 .g(g[i]),
//                 .p(p[i])
//             );
//         end
//     endgenerate

//     // --- Stage 2: group by 8 bits (4 blocks) ---
//     wire gout_8 [3:0];
//     wire pout_8 [3:0];
//     wire [6:0] cout_8 [3:0];
//     wire [3:0] carry_8;  // carry between 8-bit blocks

//     assign carry_8[0] = cin;

//     // Block 0: bits [7:0]
//     gp_8 gp8_0 (
//         .gin(g[7:0]),
//         .pin(p[7:0]),
//         .cin(carry_8[0]),
//         .gout(gout_8[0]),
//         .pout(pout_8[0]),
//         .cout(cout_8[0])
//     );

//     assign carry_8[1] = gout_8[0] | (pout_8[0] & carry_8[0]);

//     // Block 1: bits [15:8]
//     gp_8 gp8_1 (
//         .gin(g[15:8]),
//         .pin(p[15:8]),
//         .cin(carry_8[1]),
//         .gout(gout_8[1]),
//         .pout(pout_8[1]),
//         .cout(cout_8[1])
//     );

//     assign carry_8[2] = gout_8[1] | (pout_8[1] & carry_8[1]);

//     // Block 2: bits [23:16]
//     gp_8 gp8_2 (
//         .gin(g[23:16]),
//         .pin(p[23:16]),
//         .cin(carry_8[2]),
//         .gout(gout_8[2]),
//         .pout(pout_8[2]),
//         .cout(cout_8[2])
//     );

//     assign carry_8[3] = gout_8[2] | (pout_8[2] & carry_8[2]);

//     // Block 3: bits [31:24]
//     gp_8 gp8_3 (
//         .gin(g[31:24]),
//         .pin(p[31:24]),
//         .cin(carry_8[3]),
//         .gout(gout_8[3]),
//         .pout(pout_8[3]),
//         .cout(cout_8[3])
//     );

//     // Carry out của toàn bộ 32 bit (nếu cần)
//     wire cout_final;
//     assign cout_final = gout_8[3] | (pout_8[3] & carry_8[3]);

//     // --- Stage 3: generate carries cho từng bit ---
//     wire [31:0] carry;
//     assign carry[0] = cin;

//     // Nối carry trong mỗi nhóm 8 bit
//     assign carry[1]  = g[0] | (p[0] & carry[0]);
//     assign carry[2]  = g[1] | (p[1] & carry[1]);
//     assign carry[3]  = g[2] | (p[2] & carry[2]);
//     assign carry[4]  = g[3] | (p[3] & carry[3]);
//     assign carry[5]  = g[4] | (p[4] & carry[4]);
//     assign carry[6]  = g[5] | (p[5] & carry[5]);
//     assign carry[7]  = g[6] | (p[6] & carry[6]);
//     assign carry[8]  = g[7] | (p[7] & carry[7]);

//     assign carry[9]  = g[8]  | (p[8]  & carry[8]);
//     assign carry[10] = g[9]  | (p[9]  & carry[9]);
//     assign carry[11] = g[10] | (p[10] & carry[10]);
//     assign carry[12] = g[11] | (p[11] & carry[11]);
//     assign carry[13] = g[12] | (p[12] & carry[12]);
//     assign carry[14] = g[13] | (p[13] & carry[13]);
//     assign carry[15] = g[14] | (p[14] & carry[14]);
//     assign carry[16] = g[15] | (p[15] & carry[15]);

//     assign carry[17] = g[16] | (p[16] & carry[16]);
//     assign carry[18] = g[17] | (p[17] & carry[17]);
//     assign carry[19] = g[18] | (p[18] & carry[18]);
//     assign carry[20] = g[19] | (p[19] & carry[19]);
//     assign carry[21] = g[20] | (p[20] & carry[20]);
//     assign carry[22] = g[21] | (p[21] & carry[21]);
//     assign carry[23] = g[22] | (p[22] & carry[22]);
//     assign carry[24] = g[23] | (p[23] & carry[23]);

//     assign carry[25] = g[24] | (p[24] & carry[24]);
//     assign carry[26] = g[25] | (p[25] & carry[25]);
//     assign carry[27] = g[26] | (p[26] & carry[26]);
//     assign carry[28] = g[27] | (p[27] & carry[27]);
//     assign carry[29] = g[28] | (p[28] & carry[28]);
//     assign carry[30] = g[29] | (p[29] & carry[29]);
//     assign carry[31] = g[30] | (p[30] & carry[30]);

//     // --- Stage 4: sum output ---
//     assign sum = a ^ b ^ carry[31:0];
// endmodule


// `timescale 1ns / 1ns

// // Module tạo Generate (g) và Propagate (p) cho 1 bit
// module gp1(
//     input wire a, b,
//     output wire g, p
// );
//     assign g = a & b;
//     assign p = a | b;
// endmodule

// // Module CLA 4-bit
// module gp_4(
//     input wire [3:0] gin, pin,
//     input wire cin,
//     output wire gout, pout,
//     output wire [2:0] cout // Các carry nội bộ: c1, c2, c3 (c4 là cout của block)
// );
//     wire [3:0] g;
//     wire [3:0] p;
    
//     // Tính g, p nội bộ (thực ra gin/pin đã là g/p rồi, nhưng gán lại cho rõ cấu trúc)
//     assign g = gin;
//     assign p = pin;

//     // Tính Carry nội bộ (Internal Carries)
//     assign cout[0] = g[0] | (p[0] & cin);            // c1
//     assign cout[1] = g[1] | (p[1] & cout[0]);        // c2
//     assign cout[2] = g[2] | (p[2] & cout[1]);        // c3

//     // Group Generate (gout) - Lookahead: Không phụ thuộc vào cin
//     assign gout = g[3] | 
//                   (p[3] & g[2]) | 
//                   (p[3] & p[2] & g[1]) | 
//                   (p[3] & p[2] & p[1] & g[0]);

//     // Group Propagate (pout) - Lookahead: Không phụ thuộc vào cin
//     assign pout = p[3] & p[2] & p[1] & p[0];
    
// endmodule

// // Module CLA 8-bit (ghép từ 2 khối 4-bit)
// module gp_8(
//     input wire [7:0] gin, pin,
//     input wire cin,
//     output wire gout, pout,
//     output wire [6:0] cout // Carry nội bộ cho 7 bit bên trong (bit 8 là carry out block)
// );
//     wire gout_low, pout_low, gout_high, pout_high;
//     wire [2:0] cout_low;
//     wire [2:0] cout_high;
    
//     // Khối 4 bit thấp [3:0]
//     gp_4 gp_low(
//         .gin(gin[3:0]),
//         .pin(pin[3:0]),
//         .cin(cin),
//         .gout(gout_low),
//         .pout(pout_low),
//         .cout(cout_low)
//     );

//     // Carry ở giữa (bit thứ 4)
//     assign cout[3] = gout_low | (pout_low & cin);

//     // Khối 4 bit cao [7:4]
//     gp_4 gp_high (
//         .gin(gin[7:4]),
//         .pin(pin[7:4]),
//         .cin(cout[3]), // cin của khối cao là cout của khối thấp
//         .gout(gout_high),
//         .pout(pout_high),
//         .cout(cout_high)
//     );

//     // Gán các carry nội bộ ra output
//     assign cout[2:0] = cout_low[2:0];   // c1, c2, c3
//     // cout[3] đã gán ở trên          // c4
//     assign cout[6:4] = cout_high[2:0];  // c5, c6, c7

//     // Tính gout, pout cho cả khối 8-bit
//     assign pout = pout_high & pout_low;
//     assign gout = gout_high | (pout_high & gout_low);

// endmodule

// // Top Module: 32-bit Carry Lookahead Adder
// module cla(
//    input wire [31:0]  a, b,
//    input wire         cin,
//    output wire [31:0] sum
// );
//     // --- Stage 1: Bit-level generate & propagate ---
//     wire [31:0] g, p;
//     genvar i;
//     generate
//         for (i = 0; i < 32; i = i + 1) begin : gp1_stage
//             gp1 u_gp1 (
//                 .a(a[i]),
//                 .b(b[i]),
//                 .g(g[i]),
//                 .p(p[i])
//             );
//         end
//     endgenerate

//     // --- Stage 2: Group by 8 bits (4 blocks) ---
//     // Khởi tạo các dây nối
//     wire gout_8 [3:0];
//     wire pout_8 [3:0];
//     wire [6:0] cout_8 [3:0]; // Mỗi block 8 bit trả về 7 carry nội bộ
//     wire [3:0] carry_8;      // Carry đầu vào cho từng block 8-bit

//     // Carry vào block đầu tiên là cin của toàn mạch
//     assign carry_8[0] = cin;

//     // Block 0: bits [7:0]
//     gp_8 gp8_0 (
//         .gin(g[7:0]),
//         .pin(p[7:0]),
//         .cin(carry_8[0]),
//         .gout(gout_8[0]),
//         .pout(pout_8[0]),
//         .cout(cout_8[0])
//     );
//     // Tính Carry lookahead cho block tiếp theo
//     assign carry_8[1] = gout_8[0] | (pout_8[0] & carry_8[0]);

//     // Block 1: bits [15:8]
//     gp_8 gp8_1 (
//         .gin(g[15:8]),
//         .pin(p[15:8]),
//         .cin(carry_8[1]),
//         .gout(gout_8[1]),
//         .pout(pout_8[1]),
//         .cout(cout_8[1])
//     );
//     assign carry_8[2] = gout_8[1] | (pout_8[1] & carry_8[1]);

//     // Block 2: bits [23:16]
//     gp_8 gp8_2 (
//         .gin(g[23:16]),
//         .pin(p[23:16]),
//         .cin(carry_8[2]),
//         .gout(gout_8[2]),
//         .pout(pout_8[2]),
//         .cout(cout_8[2])
//     );
//     assign carry_8[3] = gout_8[2] | (pout_8[2] & carry_8[2]);

//     // Block 3: bits [31:24]
//     gp_8 gp8_3 (
//         .gin(g[31:24]),
//         .pin(p[31:24]),
//         .cin(carry_8[3]),
//         .gout(gout_8[3]),
//         .pout(pout_8[3]),
//         .cout(cout_8[3])
//     );
    
//     // (Optional) Cout final của 32-bit
//     wire cout_final;
//     assign cout_final = gout_8[3] | (pout_8[3] & carry_8[3]);


//     // --- Stage 3: Phân phối Carry (ĐÃ SỬA LỖI) ---
//     // Thay vì tính toán lại kiểu nối tiếp (Ripple Carry),
//     // ta lấy trực tiếp output từ các khối gp_8 ở Stage 2.
    
//     wire [31:0] carry;

//     // Block 0 (Bits 0-7)
//     assign carry[0]   = carry_8[0];      // cin
//     assign carry[7:1] = cout_8[0][6:0];  // carry nội bộ từ gp8_0

//     // Block 1 (Bits 8-15)
//     assign carry[8]    = carry_8[1];     // carry vào block 1 (lookahead)
//     assign carry[15:9] = cout_8[1][6:0]; // carry nội bộ từ gp8_1

//     // Block 2 (Bits 16-23)
//     assign carry[16]    = carry_8[2];
//     assign carry[23:17] = cout_8[2][6:0];

//     // Block 3 (Bits 24-31)
//     assign carry[24]    = carry_8[3];
//     assign carry[31:25] = cout_8[3][6:0];


//     // --- Stage 4: Sum generation ---
//     assign sum = a ^ b ^ carry;

// endmodule


`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 10/29/2025 07:40:47 AM
// Design Name:
// Module Name: cla
// Project Name:
// Target Devices:
// Tool Versions:
// Description:
//
// Dependencies:
//
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
//
//////////////////////////////////////////////////////////////////////////////////
/**
 * @param a first 1-bit input
 * @param b second 1-bit input
 * @param g whether a and b generate a carry
 * @param p whether a and b would propagate an incoming carry
 */
module gp1(input wire a, b,
           output wire g, p);
           // 1 gate delay
   assign g = a & b;
   assign p = a | b;
endmodule
/**
 * Computes aggregate generate/propagate signals over a 4-bit window.
 * @param gin incoming generate signals
 * @param pin incoming propagate signals
 * @param cin the incoming carry
 * @param gout whether these 4 bits internally would generate a carry-out (independent of cin)
 * @param pout whether these 4 bits internally would propagate an incoming carry from cin
 * @param cout the carry outs for the low-order 3 bits
 */
module gp4(input wire [3:0] gin, pin,
           input wire cin,
           output wire gout, pout,
           output wire [2:0] cout);
   //
   // TODO: your code here
   assign pout = &pin;
  
   assign gout = gin[3] | (pin[3] & gin[2]) | ((&pin[3:2]) & gin[1]) | ((&pin[3:1]) & gin[0]);
   // c1 = g0 | (p0 & cin)
   assign cout[0] = gin[0] | (pin[0] & cin);
   // c2 = g1 | (p1 & g0) | (p1&p0 & cin)
   assign cout[1] = gin[1] | (pin[1] & gin[0]) | ((&pin[1:0]) & cin);
   // c3 = g2 | (p2 & g1) | (p2&p1 & g0) | (p2&p1&p0 & cin)
   assign cout[2] = gin[2] | (pin[2] & gin[1]) | ((&pin[2:1]) & gin[0]) | ((&pin[2:0]) & cin);
endmodule
/** Same as gp4 but for an 8-bit window instead */
module gp8(input wire [7:0] gin, pin,
           input wire cin,
           output wire gout, pout,
           output wire [6:0] cout);
   // TODO: your code here
     assign pout = &pin; // p7 & ... & p0
   assign gout = gin[7]
               | (pin[7] & gin[6])
               | ((&pin[7:6]) & gin[5])
               | ((&pin[7:5]) & gin[4])
               | ((&pin[7:4]) & gin[3])
               | ((&pin[7:3]) & gin[2])
               | ((&pin[7:2]) & gin[1])
               | ((&pin[7:1]) & gin[0]);
   // c1
   assign cout[0] = gin[0] | (pin[0] & cin);
   // c2
   assign cout[1] = gin[1]
                  | (pin[1] & gin[0])
                  | ((&pin[1:0]) & cin);
   // c3
   assign cout[2] = gin[2]
                  | (pin[2] & gin[1])
                  | ((&pin[2:1]) & gin[0])
                  | ((&pin[2:0]) & cin);
   // c4
   assign cout[3] = gin[3]
                  | (pin[3] & gin[2])
                  | ((&pin[3:2]) & gin[1])
                  | ((&pin[3:1]) & gin[0])
                  | ((&pin[3:0]) & cin);
   // c5
   assign cout[4] = gin[4]
                  | (pin[4] & gin[3])
                  | ((&pin[4:3]) & gin[2])
                  | ((&pin[4:2]) & gin[1])
                  | ((&pin[4:1]) & gin[0])
                  | ((&pin[4:0]) & cin);
   // c6
   assign cout[5] = gin[5]
                  | (pin[5] & gin[4])
                  | ((&pin[5:4]) & gin[3])
                  | ((&pin[5:3]) & gin[2])
                  | ((&pin[5:2]) & gin[1])
                  | ((&pin[5:1]) & gin[0])
                  | ((&pin[5:0]) & cin);
   // c7
   assign cout[6] = gin[6]
                  | (pin[6] & gin[5])
                  | ((&pin[6:5]) & gin[4])
                  | ((&pin[6:4]) & gin[3])
                  | ((&pin[6:3]) & gin[2])
                  | ((&pin[6:2]) & gin[1])
                  | ((&pin[6:1]) & gin[0])
                  | ((&pin[6:0]) & cin);
endmodule
module cla
  (input wire [31:0] a, b,
   input wire cin,
   output wire [31:0] sum);
   // TODO: your code here
   //gp1
   wire [31:0] g, p;
   assign g = a & b;
   assign p = a | b;
   //block0 = bits [7:0], block1 = [15:8], block2 = [23:16], block3 = [31:24]
   wire gout0, pout0;
   wire gout1, pout1;
   wire gout2, pout2;
   wire gout3, pout3;
   wire [6:0] cout8_0;
   wire [6:0] cout8_1;
   wire [6:0] cout8_2;
   wire [6:0] cout8_3;
   wire c_block0, c_block1, c_block2, c_block3;
   assign c_block0 = cin;
   // instantiate gp8
   gp8 gp8_0(.gin(g[7:0]), .pin(p[7:0]), .cin(c_block0), .gout(gout0), .pout(pout0), .cout(cout8_0));
   // c_block1 depends on gout0/pout0 and c_block0
   assign c_block1 = gout0 | (pout0 & c_block0);
   gp8 gp8_1(.gin(g[15:8]), .pin(p[15:8]), .cin(c_block1), .gout(gout1), .pout(pout1), .cout(cout8_1));
   assign c_block2 = gout1 | (pout1 & c_block1);
   gp8 gp8_2(.gin(g[23:16]), .pin(p[23:16]), .cin(c_block2), .gout(gout2), .pout(pout2), .cout(cout8_2));
   assign c_block3 = gout2 | (pout2 & c_block2);
   gp8 gp8_3(.gin(g[31:24]), .pin(p[31:24]), .cin(c_block3), .gout(gout3), .pout(pout3), .cout(cout8_3));
   wire [31:0] carry;
   assign carry[0] = c_block0;
   assign carry[1] = cout8_0[0];
   assign carry[2] = cout8_0[1];
   assign carry[3] = cout8_0[2];
   assign carry[4] = cout8_0[3];
   assign carry[5] = cout8_0[4];
   assign carry[6] = cout8_0[5];
   assign carry[7] = cout8_0[6];
   assign carry[8] = c_block1;
   assign carry[9] = cout8_1[0];
   assign carry[10] = cout8_1[1];
   assign carry[11] = cout8_1[2];
   assign carry[12] = cout8_1[3];
   assign carry[13] = cout8_1[4];
   assign carry[14] = cout8_1[5];
   assign carry[15] = cout8_1[6];
   assign carry[16] = c_block2;
   assign carry[17] = cout8_2[0];
   assign carry[18] = cout8_2[1];
   assign carry[19] = cout8_2[2];
   assign carry[20] = cout8_2[3];
   assign carry[21] = cout8_2[4];
   assign carry[22] = cout8_2[5];
   assign carry[23] = cout8_2[6];
   assign carry[24] = c_block3;
   assign carry[25] = cout8_3[0];
   assign carry[26] = cout8_3[1];
   assign carry[27] = cout8_3[2];
   assign carry[28] = cout8_3[3];
   assign carry[29] = cout8_3[4];
   assign carry[30] = cout8_3[5];
   assign carry[31] = cout8_3[6];
   // final sum bit: sum[i] = a[i] ^ b[i] ^ carry[i]
   assign sum = a ^ b ^ carry;
endmodule
