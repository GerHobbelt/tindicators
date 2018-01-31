#include <iostream>
#include <fstream>
#include "fann.h"
#include "floatfann.h"
#include "stdio.h"

using namespace std;

std::string nameTrainFile;
std::string nameNet;
float desired_error = 0.01;
unsigned int max_epochs = 100;

int FANN_API test_callback(struct fann * ann, struct fann_train_data * train,
                           unsigned int max_epochs, unsigned int epochs_between_reports,
                           float wish_error, unsigned int epochs) {
    char netName[512] = {0};
    fann_test_data(ann, train);
    sprintf(netName, "%s_%d_%.5f._bit_%d.net", nameNet.c_str(), epochs, fann_get_MSE(ann), fann_get_bit_fail(ann));
    fann_save(ann, netName);
    printf("Epochs     %8d. MSE: %.5f. Fail bit: %d\n", epochs, fann_get_MSE(ann), fann_get_bit_fail(ann));
    return 0;
}

int main()
{
    // �������� ��������� ������� �������� � �������
	setlocale(LC_ALL, "Rus");
    cout << "������ ��������� ��� �������� ��������� ���� Fann" << endl;
    cout << "������� ��� ����� ��� ��������" << endl;
    while(1) {
        cin >> nameTrainFile;
        // ��������� ������� �����
        std::fstream fin(nameTrainFile, std::ios::binary | std::ios::in | std::ios::out);
        if(!fin.is_open()) {
            std::cout << "������! ���� �� ��� ������. �������� �� ����� �������� ��� �����. ���������� ��� ���!" << std::endl;
        } else {
            fin.close();
            break;
        }
    }

    cout << "���� ������!" << endl;
    cout << "������� ��� ����� ��� ���������� ���������" << endl;
    cin >> nameNet;

    cout << "������ ������ ��� ��������..." << endl;
    setlocale(LC_ALL,"English");
    struct fann_train_data* trainFannData = fann_read_train_from_file((const char*)nameTrainFile.c_str());

    const unsigned int num_input = fann_num_input_train_data(trainFannData);
    const unsigned int num_output = fann_num_output_train_data(trainFannData);
    setlocale(LC_ALL, "Rus");
    cout << "����� ������: " << num_input << " ����� �������: " << num_output << endl;


    cout << "������� ����������� ������" << endl;
    cin >> desired_error;

    cout << "������� ������������ ����� ����" << endl;
    cin >> max_epochs;

    const unsigned int epochs_between_reports = 1;

    unsigned int _hidden_layers;
    cout << "������� ����� ������� �����" << endl;
    cin >> _hidden_layers;

    const unsigned int hidden_layers = _hidden_layers;

    unsigned int num_layers = 2 + hidden_layers;
    if(num_layers < 3) num_layers = 3;
    if(num_layers > 5) num_layers = 5;

    unsigned int num_neurons_hidden = fann_num_input_train_data(trainFannData);
    cout << "������� ����� �������� c������ �����" << endl;
    cin >> num_neurons_hidden;

    cout << "������� ��� ��������� (0 - ���������� �� ���� � ����, 1 - ������ ���� �������� � �������� ���� ���������� �����)" << endl;
    int netType = 0;
    cin >> netType;
    // �������� ��������� ���� � ������ ann
    struct fann *ann = NULL;
    if(netType == 0) {
        if(num_layers == 3) {
            ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);
            //ann = fann_create_shortcut(num_layers, num_input, num_neurons_hidden, num_output);
        } else
        if(num_layers == 4) {
            ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_output);
            //ann = fann_create_shortcut(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_output);
        } else
        if(num_layers == 5) {
            ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_neurons_hidden, num_output);
            //ann = fann_create_shortcut(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_neurons_hidden, num_output);
        }
    } else
    if(netType == 1) {
        if(num_layers == 3) {
            //ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_output);
            ann = fann_create_shortcut(num_layers, num_input, num_neurons_hidden, num_output);
        } else
        if(num_layers == 4) {
            //ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_output);
            ann = fann_create_shortcut(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_output);
        } else
        if(num_layers == 5) {
            //ann = fann_create_standard(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_neurons_hidden, num_output);
            ann = fann_create_shortcut(num_layers, num_input, num_neurons_hidden, num_neurons_hidden, num_neurons_hidden, num_output);
        }
    }


    fann_set_activation_function_hidden(ann, FANN_SIGMOID_SYMMETRIC);
    fann_set_activation_function_output(ann, FANN_SIGMOID_SYMMETRIC);

    fann_set_callback(ann, test_callback);

    cout << "������ ��������" << endl;
    setlocale(LC_ALL,"English");
    //��������
    fann_train_on_data(ann, trainFannData, max_epochs, epochs_between_reports, desired_error);
    setlocale(LC_ALL, "Rus");
    cout << "�������� ���������" << endl;
    cout << "��������� ����..." << endl;
    //���������� ��������� ���� � ����
    setlocale(LC_ALL,"English");
    char netName[512] = {0};
    sprintf(netName, "%s.net", nameNet.c_str());
    fann_save(ann, netName);
    setlocale(LC_ALL, "Rus");
    cout << "���� ���������" << endl;
    fann_destroy(ann);
    return 0;
}
