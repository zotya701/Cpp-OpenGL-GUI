﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Json4CPP.Visualizer.ViewModels
{
  public class MessageBoxVM : ViewModelBase
  {
    private string mMessage;
    public string Message
    {
      get => mMessage;
      set => Set(ref mMessage, value);
    }

    public MessageBoxVM(string message)
    {
      mMessage = message;
    }
  }
}
