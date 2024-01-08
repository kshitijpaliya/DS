using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        String input = string.Empty;
        String Op1 = string.Empty;
        String Op2 = string.Empty;
        char Operator;
        double res;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '-';
            input = string.Empty;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '+';
            input = string.Empty;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '/';
            input = string.Empty;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input = input + "1";
            this.textBox1.Text += input;
        }

        private void button13_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "2";
            this.textBox1.Text += input;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "4";
            this.textBox1.Text += input;
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button15_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "9";
            this.textBox1.Text += input;
        }

        private void button12_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "3";
            this.textBox1.Text += input;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "5";
            this.textBox1.Text += input;
        }

        private void button14_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "6";
            this.textBox1.Text += input;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "7";
            this.textBox1.Text += input;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "8";
            this.textBox1.Text += input;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Op1 = input;
            Operator = '*';
            input = string.Empty;
        }

        private void button16_Click(object sender, EventArgs e)
        {
            Op2 = input;
            double num1, num2;
            double.TryParse(Op1, out num1);
            double.TryParse(Op2, out num2);
            if (Operator == '+')
            {
            res = num1 + num2;
            this.textBox1.Text = res.ToString();
            }
            else if (Operator == '-')
            {
            res = num1 - num2;
            textBox1.Text = res.ToString();
            }
            else if (Operator == '*')
            {
            res = num1 * num2;
            textBox1.Text = res.ToString();
            }
            else if (Operator == '/')
            {
            if (num2 != 0)
            {
            res = num1 / num2;
            textBox1.Text = res.ToString();
            }
            else
            {
            textBox1.Text = "DIV/Zero!";
            }
            
            input = string.Empty;
            }
}

        private void button8_Click(object sender, EventArgs e)
        {
            this.textBox1.Text = string.Empty;
            input += "0";
            this.textBox1.Text += input;
        }

        private void Form1_Load_1(object sender, EventArgs e)
        {

        }
    }
}

