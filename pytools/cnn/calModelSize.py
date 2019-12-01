#!/usr/bin/env python3
"""Calculate model size
"""
import argparse
import yaml

parser = argparse.ArgumentParser(description='run command line')
parser.add_argument('--modelfile', type = str, default = 'AlexNet.yaml', help = 'model definition file')
parser.add_argument('--mem', action = 'store_true', help = 'option for calculating memory')
opt = parser.parse_args()

dsize = 4 # data size in bytes
param_num = 0
net = ''
with open(opt.modelfile) as f:
    model = yaml.load(f, Loader = yaml.FullLoader)
    for entry in model:
        for k, v in entry.items():
            if 'misc' in k:
                dsize = v['datasize']
                net = v['net']
            if 'conv' in k:
                param_num = param_num + (v['outchnl'] * v['inchnl'] * v['kw'] * v['kh'])

# Total data size in MB
param_size = 1.0 * dsize * param_num / 1e6
print('Total data in {}: {} MB'.format(net, param_size))
